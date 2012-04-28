//a trial function to make level window 

#include"ezwin.h"
#include"rect.h"

SimpleWindow levelw("Select Level",7,3,Position(9,2));
float level;

#include"clicklevel.h"




int ApiMain()
{	
		levelw.Open();
		RectangleShape background(levelw,Position(3.5,2),Black,7,3);
		background.Draw();
		RectangleShape bar(levelw,Position(3.5,1),White,6,1);
		bar.Draw();
		RectangleShape ok(levelw,Position(1.75,2.25),Red,2.5,1);
		ok.Draw();
		levelw.RenderText(Position(1.75,2.25),"O K",Green,Red);
		RectangleShape cancel(levelw,Position(5.25,2.25),Red,2.5,1);
		cancel.Draw();
		levelw.RenderText(Position(5.25,2.25),"Cancel",Green,Red);
		levelw.SetMouseClickCallback(clicklevel);
		return 0;
}
