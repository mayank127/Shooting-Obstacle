
//sample program to get height and width of image
//used for gettin distances to place them in mainwindow.

#include"ezwin.h"
#include"bitmap.h"

SimpleWindow a("image size",28,15);

BitMap image(a);

int ApiMain()
{
	a.Open();
	image.Load("images/instruction1.xpm");
	assert(image.GetStatus() == BitMapOkay);
	image.Draw();
	float x=image.GetHeight();
	float y=image.GetWidth();
	char b[100];
	sprintf(b,"h = %f\nw = %f",x,y);
	a.RenderText(Position(14,7.5),b,Red);
	return 0;
}
