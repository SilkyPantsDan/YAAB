/*
 YAAB - Yet Another Autococker Board
 Arduino based autococker board developed around the platform and ATMEL AVR
 chips
 
 Copyright (C) 2015  Dan Silk
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "common.h"

void UI_Init();
void UI_UpdateBattery(uint8_t p_BattLevel);
void UI_Update();
void UI_Draw();
