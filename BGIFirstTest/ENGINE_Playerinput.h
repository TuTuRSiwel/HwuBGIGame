// Arthur lewis allright reserved lol 
#include "ENGINE_ini.h"

// check sign (not from me)
int sign(float x) {
	return (x > 0) - (x < 0);
}

// Movement Thread
DWORD WINAPI PlayerInput(LPVOID lpParam)
{
//Bind
int Player = 0;
int UP_BIND = 0x57;//w
int DOWN_BIND = 0x53;//s
int RIGHT_BIND = 0x44;//d
int LEFT_BIND = 0x41;//a
//initialisation

Pawn[Player].Location.x = 250;
Pawn[Player].Location.y = 250;
Pawn[Player].LocationOffset.x = 0;
Pawn[Player].LocationOffset.y = 0;
float LocationPreditction_x;
float LocationPreditction_y;
float Min_LocationPreditction_x;
float Min_LocationPreditction_y;
//cache initialisation to use for optimisation later

// const physics
const float FLOORGRIP = 0.7F;
const float COLISIONGRIP = 0.5;
const float SPEED_1 = 7;
const float MAX_SPEED = 25;
const float MIN_SPEED = 1;
const float GAMESPEED = 1;
// old engine lines could be swap 
float Engine_FLOORGRIP = FLOORGRIP / GAMESPEED;
float Engine_COLISIONGRIP = COLISIONGRIP / GAMESPEED;
float Engine_SPEED_1 = SPEED_1 / GAMESPEED;
float Engine_MAX_SPEED = MAX_SPEED / GAMESPEED;
float Engine_MIN_SPEED = MIN_SPEED / GAMESPEED;
//MovementLoop
do {

	// key binds
	if (GetAsyncKeyState(UP_BIND)) {
		Pawn[Player].LocationOffset.y += Engine_SPEED_1;
	}
	if (GetAsyncKeyState(DOWN_BIND)) {
		Pawn[Player].LocationOffset.y -= Engine_SPEED_1;
	}

	if (GetAsyncKeyState(LEFT_BIND)) {
		Pawn[Player].LocationOffset.x += Engine_SPEED_1;
	}
	if (GetAsyncKeyState(RIGHT_BIND)) {
		Pawn[Player].LocationOffset.x -= Engine_SPEED_1;
	}

	// check for speed limit
	if ((Pawn[Player].LocationOffset.x > -Engine_MIN_SPEED) && (Pawn[Player].LocationOffset.x < Engine_MIN_SPEED)) { Pawn[Player].LocationOffset.x = 0; }
	if ((Pawn[Player].LocationOffset.y > -Engine_MIN_SPEED) && (Pawn[Player].LocationOffset.y < Engine_MIN_SPEED)) { Pawn[Player].LocationOffset.y = 0; }
	if ((Pawn[Player].LocationOffset.x > Engine_MAX_SPEED) && (Pawn[Player].LocationOffset.x < -Engine_MAX_SPEED)) { Pawn[Player].LocationOffset.x = MAX_SPEED; }
	if ((Pawn[Player].LocationOffset.y > Engine_MAX_SPEED) && (Pawn[Player].LocationOffset.y < -Engine_MAX_SPEED)) { Pawn[Player].LocationOffset.y = MAX_SPEED; }
	//printf("%f , %f \n", Wall.Location.x_hitbox[0], Wall.Location.x_hitbox[1]);

	//initialize condition check calculation
	LocationPreditction_x = (Pawn[Player].Location.x - Pawn[Player].LocationOffset.x);
	LocationPreditction_y = (Pawn[Player].Location.y - Pawn[Player].LocationOffset.y);
	Min_LocationPreditction_x = (Pawn[Player].Location.x - sign(Pawn[Player].LocationOffset.x)* Engine_SPEED_1);
	Min_LocationPreditction_y = (Pawn[Player].Location.y - sign(Pawn[Player].LocationOffset.y)* Engine_SPEED_1);
	// check for colision
	for (int objectindex = 0; objectindex < 10; objectindex++)
	{

		//check for intersection on the x component (1 positive and 0 negative)
		if (
			// x axis is using reversed tester because y is reversed too
			// The hit box is segmented into 2 point per axis
			(Wall[objectindex].Location.x_hitbox[0] <= LocationPreditction_x)
			&&
			(Wall[objectindex].Location.x_hitbox[1] >= LocationPreditction_x)
			&&
			(Wall[objectindex].Location.y_hitbox[0] <= LocationPreditction_y)
			&&
			(Wall[objectindex].Location.y_hitbox[1] >= LocationPreditction_y))
			{
			//printf("%f , %f \n", Wall.Location.x_hitbox[0], Wall.Location.x_hitbox[1]);
		//smooth colision
			if (
				// check for next loop result when coliding and moving at base speed 
				(Wall[objectindex].Location.x_hitbox[0] <= Min_LocationPreditction_x)
				&&
				(Wall[objectindex].Location.x_hitbox[1] >= Min_LocationPreditction_x)
				&&
				(Wall[objectindex].Location.y_hitbox[0] <= Min_LocationPreditction_y)
				&&
				(Wall[objectindex].Location.y_hitbox[1] >= Min_LocationPreditction_y))
				{
					/* check for smooth colision movement state (moving on the side of a colision)
						if the player is on the side of an object and is offset is inside on one component that mean that the player is free to move
						on the other component axis as such 
						exemple : if the player is on the left of a cube and is moving to the right then is next location is inside the cube however if the player is doing
						such a thing it is imposible that he is on top of the cube because moving right while on top wouldn't trigger colision
						so only one offset can be denied for any rectangular shape.
					*/
					if (
					(Wall[objectindex].Location.x_hitbox[0] <= Min_LocationPreditction_x) && (Wall[objectindex].Location.x_hitbox[0] >= Pawn[Player].Location.x)
					||
					(Wall[objectindex].Location.x_hitbox[1] >= Min_LocationPreditction_x) && (Wall[objectindex].Location.x_hitbox[1] <= Pawn[Player].Location.x))
					{Pawn[Player].LocationOffset.x = 0;}
					else { Pawn[Player].LocationOffset.y = 0; }
				}
			else
				{
					// ensure that if the player does not colide at base speed then the player can use that base speed for smooth colision on the next loop
					Pawn[Player].LocationOffset.x = sign(Pawn[Player].LocationOffset.x) * Engine_SPEED_1;
					Pawn[Player].LocationOffset.y = sign(Pawn[Player].LocationOffset.y) * Engine_SPEED_1;
				}
		}

	}

	// grip and set location
	Pawn[Player].Location.y += -Pawn[Player].LocationOffset.y;
	Pawn[Player].Location.x += -Pawn[Player].LocationOffset.x;
	Pawn[Player].LocationOffset.x *= Engine_FLOORGRIP;
	Pawn[Player].LocationOffset.y *= Engine_FLOORGRIP;

	//printf("%f %f \n", Pawn[Player].Location.x, Pawn[Player].Location.y);
	// check for colision


	// delay check input
	delay(64);//64ms
} 
while (true);
}
