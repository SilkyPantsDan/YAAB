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

#include "../common.h"

#include "../AVR/pins.h"
#include "../AVR/OLED/ssd1306_oled.h"

#include "strings.h"
#include "UIButton.h"

#define MAX_DEPTH 5

///
/// State Machine macros
#define STATE_ENTER(state) state ##_OnEnter()
#define STATE_UPDATE(state) state ##_Update()

#define DECLARE_STATE(state) \
void STATE_ENTER(state); \
void STATE_UPDATE(state);

#define CASE_ENTER_STATE(state) \
case state: \
STATE_ENTER(state); \
break;

#define CASE_UPDATE_STATE(state) \
case state: \
STATE_UPDATE(state); \
break;

enum MenuStates
{
    GameScreen,
    MenuRoot,

	Profiles = 10,
	Timers,
	Display,
	Training,
	Setup,

	SetGameTimer = 20,
	SetAlarmTimer,

	DisplayGraphic = 30,

	// Training = 40,

	SetupEyes = 50,
	SetupTimings,
	SetupModes,
	SetupPower,

	EyesBallValue = 60,
};

enum CursorDirection
{
	CUR_Up = -1,
	CUR_Down = 1,
};

enum GameScreenModes
{
	GSM_Graphic,
	GSM_Timer,
	GSM_Stats,
	GSM_Off
};

class UserInterface
{
public:
    void Init();
    void OnSecond();
    void Update();
    void UpdateControls();
    void Draw();

private:
    //MenuStates m_CurrentState;
    MenuStates m_States[MAX_DEPTH];


    SSD1306_OLED m_Display;

    uint8_t battLevel;
	uint8_t eyeAnimIdx;

	uint8_t m_NumOptions;
	uint8_t m_CurrentOption;

    uint8_t m_CurrentDepth;

    UIButton m_UpButton;
    UIButton m_OkButton;
	UIButton m_DnButton;

    MenuStates CurrentState() { return m_States[m_CurrentDepth]; }
    MenuStates PreviousState() { return m_CurrentDepth > 0 ? m_States[m_CurrentDepth - 1] : GameScreen; }

	void ChangeOption(bool up);
	void ShowCursor(bool show);

    void PushState(MenuStates p_NewState);
    void PopState();

    void EnterState();
    void SetHeaderText(const char* const* string);
    void CreateOption(const char* const* string);

    void DrawString_P(uint8_t x, uint8_t y, const char* const* string);
    void DrawBatteryLevel(uint8_t battPercent);

	DECLARE_STATE(GameScreen)
	DECLARE_STATE(MenuRoot)

	DECLARE_STATE(Profiles)
	DECLARE_STATE(Timers)
	DECLARE_STATE(Display)
	DECLARE_STATE(Training)
	DECLARE_STATE(Setup)

	DECLARE_STATE(SetGameTimer)
	DECLARE_STATE(SetAlarmTimer)

	DECLARE_STATE(DisplayGraphic)

	DECLARE_STATE(SetupEyes)
	DECLARE_STATE(SetupTimings)
	DECLARE_STATE(SetupModes)
	DECLARE_STATE(SetupPower)

	DECLARE_STATE(EyesBallValue)

};