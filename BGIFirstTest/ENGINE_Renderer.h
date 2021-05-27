// Arthur lewis allright reserved "lol"
#include "ENGINE_ini.h"

int pagebuffer = 0;
int inigraph() {

	// Initialise graphic window
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "");
	printf("graph initialized \n");
	return 0;
}
/*
int DoubleBuffering(int pagebuffer) {
	//double buffering
	pagebuffer = 1 - pagebuffer;//target backbuffer
	setactivepage(pagebuffer);//set backbuffer active 
	setvisualpage(1 - pagebuffer);// set backbuffer active
	//printf("%d\n",pagebuffer);
	printf("doublebuffer %d \n", pagebuffer);
	return pagebuffer;
}
*/
// RenderThread

DWORD WINAPI RENDER_DoubleBuffering(LPVOID lpParam)
{
	//double buffering
	extern pagebuffer;
	pagebuffer = 1 - pagebuffer;//target backbuffer
	setactivepage(pagebuffer);//set backbuffer active 
	setvisualpage(1 - pagebuffer);// set backbuffer actives
	//printf("doublebuffer %d \n", pagebuffer);
	return pagebuffer;
}

DWORD WINAPI RendererStart(LPVOID lpParam)
{
	inigraph();
	
	HANDLE hRendererDBThread;
	DWORD ThreadrendererDB_ID;
	hRendererDBThread = CreateThread(NULL,0,RENDER_DoubleBuffering,NULL,0,&ThreadrendererDB_ID);
	if (hRendererDBThread == NULL) { printf("Thread creation failed"); }

	do{
		//double buffering
		cleardevice();
		//graphic UPDATE
		for (int Pawnindex = 0; Pawnindex < 10; Pawnindex++)
		{
			circle((int)Pawn[Pawnindex].Location.x,(int)Pawn[Pawnindex].Location.y, 40);
		}
		for (int objectindex = 0; objectindex < 24; objectindex++)
		{
			//printf("Drawing rectangle of index %d\n", objectindex);
			bar((int)Wall[objectindex].Location.x_hitbox[0]+35, (int)Wall[objectindex].Location.y_hitbox[0] + 35, (int)Wall[objectindex].Location.x_hitbox[1] - 35, (int)Wall[objectindex].Location.y_hitbox[1] - 35);//reduce the box drawn to match the pawn to wall collision visual
		}
		////////sprites
		
		//int width, height, bpp;

		//uint8_t* rgb_image = stbi_load("image.png", &width, &height, &bpp, 3);
		//putimage(15, 15,rgb_image, XOR_PUT);
		//stbi_image_free(rgb_image);



		////////



		RENDER_DoubleBuffering(0);
		delay(1); //100 fps however doesn't really matter because their is no interpolation function in the moovement loop
	} 
	while (true);

}