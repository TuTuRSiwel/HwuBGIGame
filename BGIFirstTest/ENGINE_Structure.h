#include "ENGINE_ini.h"
// arthur lewis allright reserved "lol" 

// structure 

struct Location
{
	float x, y;//members x and y
	float x_hitbox[2] ;
	float y_hitbox[2] ;
};

struct LocationOffset
{
	float x, y;//members x and y of the offset
};

// pawn or object
struct Pawn
{
	struct Location Location;

	struct LocationOffset LocationOffset;

}Pawn[10];

//walls
struct Wall
{
	struct Location Location;

	struct LocationOffset LocationOffset;

}Wall[25];
/*
struct Highground
{
	struct Location Location;

	struct LocationOffset LocationOffset;

}Highground[10];

struct Ground
{
	struct Location Location;
	
	struct LocationOffset LocationOffset;

}Ground[10];

struct Level
{
	struct Ground Ground;
	struct Wall Wall;
	struct Highground Highground;

}Level[10];
*/

//setwall function is setting a wall when given in argument a wall index number (WallID) , a position , a width and an height
void SetWall(int WallID,int x,int y,int width, int height) {
	printf("settingWall at %d %d %d %d %d\n", WallID, x, y, width, height);
	Wall[WallID].Location.x = x;
	Wall[WallID].Location.y = y;
	// set x hitbox range
	Wall[WallID].Location.x_hitbox[0] = Wall[WallID].Location.x - width;
	Wall[WallID].Location.x_hitbox[1] = Wall[WallID].Location.x + width;
	//printf("setting hit box on x range (x_hitbox[0] :%f \n x_hitbox[1]:%f \n)", Wall[WallID].Location.x_hitbox[0], Wall[WallID].Location.x_hitbox[1]);
	// set y hitbox range
	Wall[WallID].Location.y_hitbox[0] = Wall[WallID].Location.y - height;
	Wall[WallID].Location.y_hitbox[1] = Wall[WallID].Location.y + height;
	//printf("setting hit box on y range (x_hitbox[0] :%f \n x_hitbox[1]:%f)", Wall[WallID].Location.y_hitbox[0], Wall[WallID].Location.y_hitbox[1]);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////LEVELS///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//setting level by placing walls in the level
void SetLevel(int levelID) {
	switch (levelID)
	{
	case 1:
		printf("settinglevel 1\n");
		SetWall(0 ,500,20,550,55);
		SetWall(1, 500,480, 550, 55);
		SetWall(2, 0, 100, 45, 550);
		SetWall(3, 640, 100, 45, 550);
		//hello world
		//h
		SetWall(4, 100, 100, 45, 75);
		SetWall(5, 200, 100, 45, 75);
		SetWall(6, 150, 100, 75, 45);
		//e
		SetWall(7, 255, 100, 45, 60);
		SetWall(8, 270, 100, 60, 45);
		SetWall(9, 270, 70, 60, 45);
		SetWall(10, 270, 130, 60, 45);
		//l
		SetWall(11, 340, 100, 45, 75);
		//l
		SetWall(12, 400, 100, 45, 75);

		//o
		SetWall(13, 455, 100, 45, 60);
		//SetWall(14, 470, 100, 60, 45);
		SetWall(15, 480, 70, 70, 45);
		SetWall(16, 480, 130, 70, 45);
		SetWall(17, 505, 100, 45, 60);
		break;
	case 2:
		printf("settinglevel 2\n");
		SetWall(0, 500, 20, 550, 55);
		SetWall(1, 500, 480, 550, 55);
		SetWall(2, 0, 100, 45, 550);
		SetWall(3, 640, 100, 45, 550);
		/////
		SetWall(4, 400, 175, 75, 75);
		SetWall(5, 500, 400, 75, 75);
		SetWall(6, 150, 350, 75, 50);
		break;
	case 3:
		printf("settinglevel 3\n");
		SetWall(0, 500, 20, 550, 55);
		SetWall(1, 500, 480, 550, 55);
		SetWall(2, 0, 100, 45, 550);
		SetWall(3, 640, 100, 45, 550);
		SetWall(4, 350, 200, 75, 75);
		break;
	default:
		break;
	}



}

void ClearWall(){
// setting evey wall very far away from the screen
for(int i = 0 ; i<= 24;i++){
SetWall(i, 10000, 10000, 0, 0);

}

}