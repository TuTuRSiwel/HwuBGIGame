#include "ENGINE_ini.h"
#include "ENGINE_Playerinput.h"
//#include "ENGINE_Renderer.h"
void CallPlayerInputThread(){
	HANDLE hThread;
	DWORD ThreadID;
	hThread = CreateThread(
		NULL,
		0,
		PlayerInput,
		NULL,
		0,
		&ThreadID
	);

	if (hThread == NULL) { printf("Thread creation failed"); }
}

void CallRendererThread() {
	HANDLE hRendererThread;
	DWORD ThreadrendererID;
	hRendererThread = CreateThread(
		NULL,
		0,
		RendererStart,
		NULL,
		0,
		&ThreadrendererID
	);

	if (hRendererThread == NULL) { printf("Thread creation failed"); }
}