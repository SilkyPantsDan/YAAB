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

#include "UserInterface.h"

#include "settings.h"
#include "BreechEyesTask.h"

extern BreechEyesTask eyeCycleTask;
extern MarkerProfile g_CurrentMode;

void UserInterface::GameScreen_OnEnter()
{
    SetHeaderText(&(ModeHeaderStrings[g_CurrentMode.profileNameIndex]));
}

void UserInterface::GameScreen_Update()
{
	m_Display.DrawGraphic(0);
	/*
    char buffer[16];

	// Draw Graph
	m_Display.DrawLine( 18, 44,  18, 60);
	m_Display.DrawLine( 18, 60, 109, 60);
	m_Display.DrawLine(109, 44, 109, 60);

	// Mark Lines
	m_Display.DrawLine(16, 46, 17, 46);
	m_Display.DrawLine(110, 46, 111, 46);
	*/
	
    
    if (m_OkButton.GetButtonState() == UBS_Held) {
        SetState(MenuRoot);
    }
}