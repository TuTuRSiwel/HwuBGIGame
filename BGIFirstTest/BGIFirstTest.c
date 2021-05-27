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

	//////////////////////////////////// Calling Main Threads from ENGINE_Threadmanager.h
	CallPlayerInputThread();
	CallRendererThread();
	//////////////////////////////////// setting first level 
	SetLevel(1);
//Gameloop
	printf("setting hit box on y range (x_hitbox[1] :%f \n x_hitbox[1]:%f)", Wall[1].Location.y_hitbox[1], Wall[1].Location.y_hitbox[1]);
	int MAXLEVELID = 3;
	int indexlevelID = 1;

	// level changer
	while (true) 
	{
	if (GetAsyncKeyState(0x20)) {
		indexlevelID = indexlevelID + 1;
		if (indexlevelID > MAXLEVELID) { indexlevelID = 1; };
		ClearWall();
		SetLevel(indexlevelID);
		delay(500);
		}
	delay(100);

	}
// wait for key pressed
readkey();

// close graphic
closegraph();
}

