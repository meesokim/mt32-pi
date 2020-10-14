//
// font6x8.h
//
// mt32-pi - A bare-metal Roland MT-32 emulator for Raspberry Pi
// Copyright (C) 2020  Dale Whinham <daleyo@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef _font6x8_h
#define _font6x8_h

#include <circle/types.h>

constexpr u8 Font6x8[97][8] =
{
	{
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000000,
		0b000000,
		0b000100,
		0b000000
	},
	{
		0b001010,
		0b001010,
		0b001010,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b001010,
		0b001010,
		0b011111,
		0b001010,
		0b011111,
		0b001010,
		0b001010,
		0b000000
	},
	{
		0b000100,
		0b001111,
		0b010100,
		0b001110,
		0b000101,
		0b011110,
		0b000100,
		0b000000
	},
	{
		0b011000,
		0b011001,
		0b000010,
		0b000100,
		0b001000,
		0b010011,
		0b000011,
		0b000000
	},
	{
		0b001100,
		0b010010,
		0b010100,
		0b001000,
		0b010101,
		0b010010,
		0b001101,
		0b000000
	},
	{
		0b001100,
		0b000100,
		0b001000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b000010,
		0b000100,
		0b001000,
		0b001000,
		0b001000,
		0b000100,
		0b000010,
		0b000000
	},
	{
		0b001000,
		0b000100,
		0b000010,
		0b000010,
		0b000010,
		0b000100,
		0b001000,
		0b000000
	},
	{
		0b000000,
		0b000100,
		0b010101,
		0b001110,
		0b010101,
		0b000100,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b000100,
		0b000100,
		0b011111,
		0b000100,
		0b000100,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b001100,
		0b000100,
		0b001000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b000000,
		0b011111,
		0b000000,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b001100,
		0b001100,
		0b000000
	},
	{
		0b000000,
		0b000001,
		0b000010,
		0b000100,
		0b001000,
		0b010000,
		0b000000,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010011,
		0b010101,
		0b011001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b000100,
		0b001100,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b001110,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b000001,
		0b000010,
		0b000100,
		0b001000,
		0b011111,
		0b000000
	},
	{
		0b011111,
		0b000010,
		0b000100,
		0b000010,
		0b000001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b000010,
		0b000110,
		0b001010,
		0b010010,
		0b011111,
		0b000010,
		0b000010,
		0b000000
	},
	{
		0b011111,
		0b010000,
		0b011110,
		0b000001,
		0b000001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b000110,
		0b001000,
		0b010000,
		0b011110,
		0b010001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b011111,
		0b000001,
		0b000010,
		0b000100,
		0b001000,
		0b001000,
		0b001000,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010001,
		0b001110,
		0b010001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010001,
		0b001111,
		0b000001,
		0b000010,
		0b001100,
		0b000000
	},
	{
		0b000000,
		0b001100,
		0b001100,
		0b000000,
		0b001100,
		0b001100,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b001100,
		0b001100,
		0b000000,
		0b001100,
		0b000100,
		0b001000,
		0b000000
	},
	{
		0b000010,
		0b000100,
		0b001000,
		0b010000,
		0b001000,
		0b000100,
		0b000010,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b011111,
		0b000000,
		0b011111,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b010000,
		0b001000,
		0b000100,
		0b000010,
		0b000100,
		0b001000,
		0b010000,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b000001,
		0b000010,
		0b000100,
		0b000000,
		0b000100,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010111,
		0b010101,
		0b010111,
		0b010000,
		0b001110,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010001,
		0b010001,
		0b011111,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b011110,
		0b010001,
		0b010001,
		0b011110,
		0b010001,
		0b010001,
		0b011110,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010000,
		0b010000,
		0b010000,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b011100,
		0b010010,
		0b010001,
		0b010001,
		0b010001,
		0b010010,
		0b011100,
		0b000000
	},
	{
		0b011111,
		0b010000,
		0b010000,
		0b011110,
		0b010000,
		0b010000,
		0b011111,
		0b000000
	},
	{
		0b011111,
		0b010000,
		0b010000,
		0b011110,
		0b010000,
		0b010000,
		0b010000,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010000,
		0b010111,
		0b010001,
		0b010001,
		0b001111,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b010001,
		0b011111,
		0b010001,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b001110,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b001110,
		0b000000
	},
	{
		0b000111,
		0b000010,
		0b000010,
		0b000010,
		0b000010,
		0b010010,
		0b001100,
		0b000000
	},
	{
		0b010001,
		0b010010,
		0b010100,
		0b011000,
		0b010100,
		0b010010,
		0b010001,
		0b000000
	},
	{
		0b010000,
		0b010000,
		0b010000,
		0b010000,
		0b010000,
		0b010000,
		0b011111,
		0b000000
	},
	{
		0b010001,
		0b011011,
		0b010101,
		0b010101,
		0b010001,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b011001,
		0b010101,
		0b010011,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b011110,
		0b010001,
		0b010001,
		0b011110,
		0b010000,
		0b010000,
		0b010000,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010001,
		0b010001,
		0b010101,
		0b010010,
		0b001101,
		0b000000
	},
	{
		0b011110,
		0b010001,
		0b010001,
		0b011110,
		0b010100,
		0b010010,
		0b010001,
		0b000000
	},
	{
		0b001110,
		0b010001,
		0b010000,
		0b001110,
		0b000001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b011111,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b010001,
		0b001010,
		0b000100,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b010001,
		0b010101,
		0b010101,
		0b010101,
		0b001010,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b001010,
		0b000100,
		0b001010,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b010001,
		0b010001,
		0b010001,
		0b001010,
		0b000100,
		0b000100,
		0b000100,
		0b000000
	},
	{
		0b011111,
		0b000001,
		0b000010,
		0b000100,
		0b001000,
		0b010000,
		0b011111,
		0b000000
	},
	{
		0b001110,
		0b001000,
		0b001000,
		0b001000,
		0b001000,
		0b001000,
		0b001110,
		0b000000
	},
	{
		0b010001,
		0b001010,
		0b011111,
		0b000100,
		0b011111,
		0b000100,
		0b000100,
		0b000000
	},
	{
		0b001110,
		0b000010,
		0b000010,
		0b000010,
		0b000010,
		0b000010,
		0b001110,
		0b000000
	},
	{
		0b000100,
		0b001010,
		0b010001,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b011111,
		0b000000
	},
	{
		0b000110,
		0b000100,
		0b000010,
		0b000000,
		0b000000,
		0b000000,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001110,
		0b000001,
		0b001111,
		0b010001,
		0b001111,
		0b000000
	},
	{
		0b010000,
		0b010000,
		0b011110,
		0b010001,
		0b010001,
		0b010001,
		0b011110,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001111,
		0b010000,
		0b010000,
		0b010000,
		0b001111,
		0b000000
	},
	{
		0b000001,
		0b000001,
		0b001111,
		0b010001,
		0b010001,
		0b010001,
		0b001111,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001110,
		0b010001,
		0b011111,
		0b010000,
		0b001110,
		0b000000
	},
	{
		0b000011,
		0b000100,
		0b011111,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001111,
		0b010001,
		0b001111,
		0b000001,
		0b001110,
		0b000000
	},
	{
		0b010000,
		0b010000,
		0b010110,
		0b011001,
		0b010001,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b000100,
		0b000000,
		0b001100,
		0b000100,
		0b000100,
		0b000100,
		0b001110,
		0b000000
	},
	{
		0b000010,
		0b000000,
		0b000110,
		0b000010,
		0b000010,
		0b010010,
		0b001100,
		0b000000
	},
	{
		0b010000,
		0b010000,
		0b010010,
		0b010100,
		0b011000,
		0b010100,
		0b010010,
		0b000000
	},
	{
		0b001100,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b000100,
		0b001110,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b011110,
		0b010101,
		0b010101,
		0b010101,
		0b010101,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010110,
		0b011001,
		0b010001,
		0b010001,
		0b010001,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001110,
		0b010001,
		0b010001,
		0b010001,
		0b001110,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b011110,
		0b010001,
		0b011110,
		0b010000,
		0b010000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001111,
		0b010001,
		0b001111,
		0b000001,
		0b000001,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010110,
		0b011000,
		0b010000,
		0b010000,
		0b010000,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b001111,
		0b010000,
		0b001110,
		0b000001,
		0b011110,
		0b000000
	},
	{
		0b000100,
		0b000100,
		0b011111,
		0b000100,
		0b000100,
		0b000100,
		0b000011,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010001,
		0b010001,
		0b010001,
		0b010011,
		0b001101,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010001,
		0b010001,
		0b010001,
		0b001010,
		0b000100,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010001,
		0b010001,
		0b010101,
		0b010101,
		0b001010,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010001,
		0b001010,
		0b000100,
		0b001010,
		0b010001,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b010001,
		0b010001,
		0b001111,
		0b000001,
		0b001110,
		0b000000
	},
	{
		0b000000,
		0b000000,
		0b011111,
		0b000010,
		0b000100,
		0b001000,
		0b011111,
		0b000000
	},
	{
		0b000110,
		0b001000,
		0b001000,
		0b010000,
		0b001000,
		0b001000,
		0b000110,
		0b000000
	},
	{
		0b000100,
		0b000100,
		0b000100,
		0b000000,
		0b000100,
		0b000100,
		0b000100,
		0b000000
	},
	{
		0b001100,
		0b000010,
		0b000010,
		0b000001,
		0b000010,
		0b000010,
		0b001100,
		0b000000
	},
	{
		0b000000,
		0b000100,
		0b000010,
		0b011111,
		0b000010,
		0b000100,
		0b000000,
		0b000000
	},
	{
		0b000000,
		0b000100,
		0b001000,
		0b011111,
		0b001000,
		0b000100,
		0b000000,
		0b000000
	},
	// Normally 0xFF in the HD44780 ROM font, but this font is incomplete so
	// let's just add the full block character onto the end as 0x60
	{
		0b111111,
		0b111111,
		0b111111,
		0b111111,
		0b111111,
		0b111111,
		0b111111,
		0b111111
	}
};

#endif
