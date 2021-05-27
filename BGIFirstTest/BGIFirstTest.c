// BGIFirstTest.c : Example graphic application
//

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <process.h>

#include "ENGINE_Structure.h"
#include "ENGINE_Renderer.h"
#include "ENGINE_Threadmanager.h"

void main(void)
{

// Initialise graphic window
	inigraph();
/*
//create a thread to move the character
	HANDLE hThread;
	DWORD ThreadID;
	hThread = CreateThread(
		NULL,
		0,
		Movement,
		NULL,
		0,
		&ThreadID
		);

	if (hThread == NULL) { printf("Thread creation failed"); }
	*/
	////////////////////////////////////
	CallPlayerInputThread();
	CallRendererThread();

	SetLevel(1);
//Gameloop
	printf("setting hit box on y range (x_hitbox[1] :%f \n x_hitbox[1]:%f)", Wall[1].Location.y_hitbox[1], Wall[1].Location.y_hitbox[1]);
	while (true) 
	{
	delay(1000);
	}
// wait for key pressed
readkey();

// close graphic
closegraph();
}

