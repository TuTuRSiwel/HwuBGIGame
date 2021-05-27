#include "ENGINE_ini.h"
// arthur lewis allright reserved lol 

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


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////LEVEL///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////



struct Wall
{
	struct Location Location;

	struct LocationOffset LocationOffset;

}Wall[11];

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

void SetWall(int WallID,int x,int y,int width, int height) {
	printf("settingWall at %d %d %d %d\n", WallID, x, y, width, height);
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


void SetLevel(int levelID) {
	switch (levelID)
	{
	case 1:
		printf("settinglevel\n");
		SetWall(0 ,500,-10,515,20);
		SetWall(1, 500,490, 515, 20);
		SetWall(2, -10, 100, 20, 515);
		SetWall(3, 650, 100, 20, 515);
		break;
	default:
		break;
	}



}