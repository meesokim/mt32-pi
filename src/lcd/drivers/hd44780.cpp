//
// hd44780.cpp
//
// mt32-pi - A baremetal MIDI synthesizer for Raspberry Pi
// Copyright (C) 2020-2021 Dale Whinham <daleyo@gmail.com>
//
// This file is part of mt32-pi.
//
// mt32-pi is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// mt32-pi is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// mt32-pi. If not, see <http://www.gnu.org/licenses/>.
//

#include <circle/logger.h>
#include <circle/timer.h>

#include "lcd/barchars.h"
#include "lcd/drivers/hd44780.h"

CHD44780Base::CHD44780Base(u8 nColumns, u8 nRows)
	: CLCD(),
	  m_nRows(nRows),
	  m_nColumns(nColumns),
	  m_RowOffsets{ 0, 0x40, m_nColumns, u8(0x40 + m_nColumns) },
	  m_BarCharSet(TBarCharSet::None)
{
}

void CHD44780Base::WriteByte(u8 nByte, TWriteMode Mode)
{
	WriteNybble(nByte >> 4, Mode);
	WriteNybble(nByte, Mode);
}

void CHD44780Base::WriteCommand(u8 nByte)
{
	// RS = LOW for command mode
	WriteByte(nByte, TWriteMode::Command);
}

void CHD44780Base::WriteData(u8 nByte)
{
	// RS = HIGH for data mode
	WriteByte(nByte, TWriteMode::Data);
}

void CHD44780Base::WriteData(const u8* pBytes, size_t nSize)
{
	for (size_t i = 0; i < nSize; ++i)
		WriteData(pBytes[i]);
}

void CHD44780Base::SetCustomChar(u8 nIndex, const u8 nCharData[8])
{
	assert(nIndex < 8);
	WriteCommand(0x40 | (nIndex << 3));

	for (u8 i = 0; i < 8; ++i)
		WriteData(nCharData[i]);
}

void CHD44780Base::SetBarChars(TBarCharSet CharSet)
{
	if (CharSet == m_BarCharSet)
		return;

	if (CharSet == TBarCharSet::Wide)
	{
		for (size_t i = 0; i < Utility::ArraySize(CustomBarCharDataWide); ++i)
			SetCustomChar(i, CustomBarCharDataWide[i]);
	}
	else
	{
		for (size_t i = 0; i < Utility::ArraySize(CustomBarCharDataNarrow); ++i)
			SetCustomChar(i, CustomBarCharDataNarrow[i]);
	}

	m_BarCharSet = CharSet;
}

bool CHD44780Base::Initialize()
{
	// Validate dimensions - only 20x2 and 20x4 supported for now
	if (!(m_nRows == 2 || m_nRows == 4) || m_nColumns != 20)
		return false;

	// Give the LCD some time to start up
	CTimer::SimpleMsDelay(50);

	// The following algorithm ensures the LCD is in the correct mode no matter what state it's currently in:
	// https://en.wikipedia.org/wiki/Hitachi_HD44780_LCD_controller#Mode_selection
	WriteNybble(0b0011, TWriteMode::Command);
	CTimer::SimpleMsDelay(50);
	WriteNybble(0b0011, TWriteMode::Command);
	CTimer::SimpleMsDelay(50);
	WriteNybble(0b0011, TWriteMode::Command);
	CTimer::SimpleMsDelay(50);

	// Switch to 4-bit mode
	WriteNybble(0b0010, TWriteMode::Command);
	CTimer::SimpleMsDelay(50);

	// Turn off
	WriteCommand(0b1000);

	// Clear display
	WriteCommand(0b0001);
	CTimer::SimpleMsDelay(50);

	// Home cursor
	WriteCommand(0b0010);
	CTimer::SimpleMsDelay(2);

	// Function set (4-bit, 2-line)
	WriteCommand(0b101000);

	// Set entry
	WriteCommand(0b0110);

	// Set custom characters
	SetBarChars(TBarCharSet::Wide);

	// Turn on
	WriteCommand(0b1100);

	return true;
}

void CHD44780Base::Print(const char* pText, u8 nCursorX, u8 nCursorY, bool bClearLine, bool bImmediate)
{
	WriteCommand(0x80 | m_RowOffsets[nCursorY] + nCursorX);

	const char* p = pText;
	while (*p && (p - pText) < m_nColumns)
		WriteData(*p++);

	if (bClearLine)
	{
		while ((p++ - pText) < (m_nColumns - nCursorX))
			WriteData(' ');
	}
}

void CHD44780Base::Clear(bool bImmediate)
{
	if (!bImmediate)
		return;

	WriteCommand(0b0001);
	CTimer::SimpleMsDelay(50);
}

// void CHD44780Base::DrawChannelLevels(u8 nFirstRow, u8 nRows, u8 nBarXOffset, u8 nBarSpacing, u8 nChannels, bool bDrawBarBases)
// {
// 	char LineBuf[nRows][m_nColumns];
// 	const u8 nBarHeight = nRows * 8;

// 	// Initialize with ASCII spaces
// 	memset(LineBuf, ' ', sizeof(LineBuf));

// 	// For each channel
// 	for (u8 i = 0; i < nChannels; ++i)
// 	{
// 		const u8 nCharIndex = i + i * nBarSpacing + nBarXOffset;
// 		assert(nCharIndex < 20);

// 		u8 nLevelPixels = m_ChannelLevels[i] * nBarHeight;
// 		if (bDrawBarBases && nLevelPixels == 0)
// 			nLevelPixels = 1;

// 		const u8 nFullRows  = nLevelPixels / 8;
// 		const u8 nRemainder = nLevelPixels % 8;

// 		for (u8 j = 0; j < nFullRows; ++j)
// 			LineBuf[nRows - j - 1][nCharIndex] = BarChars[8];

// 		for (u8 j = nFullRows; j < nRows; ++j)
// 			LineBuf[nRows - j - 1][nCharIndex] = BarChars[0];

// 		if (nRemainder)
// 			LineBuf[nRows - nFullRows - 1][nCharIndex] = BarChars[nRemainder];
// 	}

// 	for (u8 nRow = 0; nRow < nRows; ++nRow)
// 	{
// 		WriteCommand(0x80 | m_RowOffsets[nFirstRow + nRow]);
// 		for (u8 nColumn = 0; nColumn < m_nColumns; ++nColumn)
// 			WriteData(LineBuf[nRow][nColumn]);
// 	}
// }

// void CHD44780Base::Update(CMT32Synth& Synth)
// {
// 	CSynthLCD::Update(Synth);

// 	// Bail out if display is off
// 	if (!m_bBacklightEnabled)
// 		return;

// 	SetBarChars(TBarCharSet::Wide);
// 	UpdateChannelLevels(Synth);

// 	const bool bShowSystemMessage = m_SystemState != TSystemState::None && m_SystemState != TSystemState::DisplayingImage;

// 	if (m_nRows == 2)
// 	{
// 		if (bShowSystemMessage)
// 			Print(m_SystemMessageTextBuffer, 0, 0, true);
// 		else
// 			DrawChannelLevels(0, 1, 0, 1, MT32ChannelCount, false);

// 		if (m_SystemState != TSystemState::EnteringPowerSavingMode)
// 			Print(m_MT32TextBuffer, 0, 1, true);
// 	}
// 	else if (m_nRows == 4)
// 	{
// 		if (bShowSystemMessage)
// 		{
// 			// Clear top line
// 			Print("", 0, 0, true);
// 			Print(m_SystemMessageTextBuffer, 0, 1, true);
// 			Print("", 0, 2, true);
// 		}
// 		else
// 			DrawChannelLevels(0, 3, 0, 1, MT32ChannelCount, false);

// 		if (m_SystemState != TSystemState::EnteringPowerSavingMode)
// 			Print(m_MT32TextBuffer, 0, 3, true);
// 	}
// }

// void CHD44780Base::Update(CSoundFontSynth& Synth)
// {
// 	CSynthLCD::Update(Synth);

// 	// Bail out if display is off
// 	if (!m_bBacklightEnabled)
// 		return;

// 	SetBarChars(TBarCharSet::Narrow);
// 	UpdateChannelLevels(Synth);

// 	const bool bShowSystemMessage = m_SystemState != TSystemState::None && m_SystemState != TSystemState::DisplayingImage;

// 	if (m_nRows == 2)
// 	{
// 		if (bShowSystemMessage)
// 		{
// 			Print(m_SystemMessageTextBuffer, 0, 0, true);
// 			Print("", 0, 1, true);
// 		}
// 		else
// 			DrawChannelLevels(0, m_nRows, 2, 0, MIDIChannelCount);
// 	}
// 	else if (m_nRows == 4)
// 	{
// 		if (bShowSystemMessage)
// 		{
// 			// Clear top line
// 			Print("", 0, 0, true);
// 			Print(m_SystemMessageTextBuffer, 0, 1, true);
// 			Print("", 0, 2, true);
// 			Print("", 0, 3, true);
// 		}
// 		else
// 			DrawChannelLevels(0, m_nRows, 2, 0, MIDIChannelCount);
// 	}
// }
