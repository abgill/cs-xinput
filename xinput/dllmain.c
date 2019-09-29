// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <Windows.h>
#include <Xinput.h>
#include <stdio.h>
#include <math.h>

#pragma comment (lib, "xinput.lib")

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

typedef struct {
	int IS_CONNECTED;
	int A;
	int B;
	int X;
	int Y;

	int LB;
	int RB;

	int LS;
	int RS;

	int DPAD_UP;
	int DPAD_DOWN;
	int DPAD_LEFT;
	int DPAD_RIGHT;

	int START;
	int SELECT;

	float LEFT_STICK_X;
	float LEFT_STICK_Y;

	float RIGHT_STICK_X;
	float RIGHT_STICK_Y;

	float LEFT_TRIGGER;
	float RIGHT_TRIGGER;
}ControllerState;


// function declaration
ControllerState __declspec(dllimport) getControllerState(INT32 controller);


ControllerState initState() {
	ControllerState controller_state;

	controller_state.IS_CONNECTED = FALSE;

	controller_state.A = FALSE;
	controller_state.B = FALSE;
	controller_state.X = FALSE;
	controller_state.Y = FALSE;

	controller_state.LB = FALSE;
	controller_state.RB = FALSE;

	controller_state.LS= FALSE;
	controller_state.RS = FALSE;

	controller_state.DPAD_UP = FALSE;
	controller_state.DPAD_DOWN = FALSE;
	controller_state.DPAD_LEFT = FALSE;
	controller_state.DPAD_RIGHT= FALSE;

	controller_state.START = FALSE;
	controller_state.SELECT = FALSE;
	
	controller_state.LEFT_STICK_X = 0.0;
	controller_state.LEFT_STICK_Y = 0.0;
	controller_state.RIGHT_STICK_X = 0.0;
	controller_state.RIGHT_STICK_Y = 0.0;

	controller_state.LEFT_TRIGGER = 0.0;
	controller_state.RIGHT_TRIGGER = 0.0;

	return controller_state;
}

ControllerState getControllerState(int controller) {

	
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	ControllerState controller_state = initState();

	controller_state.IS_CONNECTED = FALSE;

	

	if (XInputGetState(controller, &state) == ERROR_SUCCESS)
	{

		controller_state.IS_CONNECTED = TRUE;

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0) {
			controller_state.A = TRUE;
		}
		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0) {
			controller_state.B = TRUE;
		}
		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0) {
			controller_state.X = TRUE;
		}
		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0) {
			controller_state.Y = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != 0) {
			controller_state.RB = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != 0) {
			controller_state.LB = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0) {
			controller_state.DPAD_UP = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0) {
			controller_state.DPAD_DOWN = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != 0) {
			controller_state.DPAD_LEFT = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != 0) {
			controller_state.DPAD_RIGHT = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0) {
			controller_state.LS = TRUE;
		}

		if ((state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != 0) {
			controller_state.RS = TRUE;
		}

		controller_state.LEFT_TRIGGER = (float)state.Gamepad.bLeftTrigger / 255;
		controller_state.RIGHT_TRIGGER = (float)state.Gamepad.bRightTrigger / 255;


		controller_state.LEFT_STICK_X = fmaxf(-1, (float)state.Gamepad.sThumbLX / 32767);
		controller_state.LEFT_STICK_Y = fmaxf(-1, (float)state.Gamepad.sThumbLY / 32767);

		float deadzoneX = 0.05f;
		float deadzoneY = 0.02f;


		controller_state.RIGHT_STICK_X = fmaxf(-1, (float)state.Gamepad.sThumbRX / 32767);
		controller_state.RIGHT_STICK_Y = fmaxf(-1, (float)state.Gamepad.sThumbRY / 32767);

		return controller_state;
	}

	return controller_state;

}



