// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <Windows.h>
#include <Xinput.h>
#include <math.h>
#include <stdio.h>

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
	INT32 IS_CONNECTED;

	INT32 A;
	INT32 B;
	INT32 X;
	INT32 Y;

	INT32 LB;
	INT32 RB;

	INT32 LS;
	INT32 RS;

	INT32 DPAD_UP;
	INT32 DPAD_DOWN;
	INT32 DPAD_LEFT;
	INT32 DPAD_RIGHT;

	INT32 START;
	INT32 SELECT;

	float LEFT_STICK_X;
	float LEFT_STICK_Y;

	float RIGHT_STICK_X;
	float RIGHT_STICK_Y;

	float LEFT_TRIGGER;
	float RIGHT_TRIGGER;
}ControllerState;


// function declaration
ControllerState __declspec(dllimport) getControllerState(INT32 controller);


void initState(ControllerState* controller_state) {

	controller_state->IS_CONNECTED = FALSE;

	controller_state->A = FALSE;
	controller_state->B = FALSE;
	controller_state->X = FALSE;
	controller_state->Y = FALSE;

	controller_state->LB = FALSE;
	controller_state->RB = FALSE;

	controller_state->LS= FALSE;
	controller_state->RS = FALSE;

	controller_state->DPAD_UP = FALSE;
	controller_state->DPAD_DOWN = FALSE;
	controller_state->DPAD_LEFT = FALSE;
	controller_state->DPAD_RIGHT= FALSE;

	controller_state->START = FALSE;
	controller_state->SELECT = FALSE;
	
	controller_state->LEFT_STICK_X = 0.0;
	controller_state->LEFT_STICK_Y = 0.0;
	controller_state->RIGHT_STICK_X = 0.0;
	controller_state->RIGHT_STICK_Y = 0.0;

	controller_state->LEFT_TRIGGER = 0.0;
	controller_state->RIGHT_TRIGGER = 0.0;

}

void updateControllerState(ControllerState* controller_state, XINPUT_STATE* state) {

	controller_state->IS_CONNECTED = TRUE;

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0) {
		controller_state->A = TRUE;
	}
	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0) {
		controller_state->B = TRUE;
	}
	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0) {
		controller_state->X = TRUE;
	}
	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0) {
		controller_state->Y = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != 0) {
		controller_state->RB = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != 0) {
		controller_state->LB = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0) {
		controller_state->DPAD_UP = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0) {
		controller_state->DPAD_DOWN = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != 0) {
		controller_state->DPAD_LEFT = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != 0) {
		controller_state->DPAD_RIGHT = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0) {
		controller_state->LS = TRUE;
	}

	if ((state->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != 0) {
		controller_state->RS = TRUE;
	}

	controller_state->LEFT_TRIGGER = max(-1, (float)state->Gamepad.bLeftTrigger / 255);
	controller_state->RIGHT_TRIGGER = (float)state->Gamepad.bRightTrigger / 255;


	float normLX = fmaxf(-1, (float)state->Gamepad.sThumbLX / 32767);
	float normLY = fmaxf(-1, (float)state->Gamepad.sThumbLY / 32767);

	float deadzoneX = 0.05f;
	float deadzoneY = 0.02f;



	controller_state->LEFT_STICK_X = normLX;
	controller_state->LEFT_STICK_Y = normLY;


	controller_state->RIGHT_STICK_X = max(-1, (float)state->Gamepad.sThumbRX / 32767);
	controller_state->RIGHT_STICK_Y = max(-1, (float)state->Gamepad.sThumbRY / 32767);
}

ControllerState getControllerState(INT32 controller) {

	
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	ControllerState controller_state;

	initState(&controller_state);

	controller_state.IS_CONNECTED = FALSE;

	

	if (XInputGetState(controller, &state) == ERROR_SUCCESS)
	{
		updateControllerState(&controller_state, &state);
		

		return controller_state;
	}

	return controller_state;

}



