



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

#ifdef __cplusplus


extern "C" {
#endif

	ControllerState __declspec(dllimport) getControllerState(INT32 controller);


#ifdef __cplusplus
}
#endif
