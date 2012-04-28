

//initial program for draing an dthrowing of ball on mouse click
//for making simultaneouse movement this idea was dropped and new file was used
int MouseClick(const Position &p) {
	check=0;
	x=p.GetXDistance();
	y=p.GetYDistance();
	length=sqrt((xcursor-xg)*(xcursor-xg)+(ycursor-yg)*(ycursor-yg));
	xgf=(xcursor-xg)/length+xg;
	ygf=(ycursor-yg)/length+yg;
	if(ycursor<yg)
	{	Game.Erase(Position(xg-1.5,yg-1.5),3,3);
		RectangleShape base(Game,Position(xg,yg),Red,28.0,0.5);
		Game.RenderLine(Position(xgf,ygf),Position(xg,yg),Red,0.5);
		base.ClearBorder();
		//background.Draw();
		//exit1.Draw();
		Game.RenderLine(Position(xgf,ygf),Position(xg,	yg),Red,0.5);
		//base.Draw();
		CircleShape ball(Game,Position(xgf,ygf),Yellow,0.5);
		ball.ClearBorder();
		ball.SetPosition(Position(xg,yg));
		
		char a[100];
		sprintf(a,"%f %f %f",x,y,length);
		Game.RenderText(Position(p),a,Red,Blue);
		
		long timei=GetMilliseconds(),timef;
		int countballpositions=0;
		float ballpos[250][2];
		float xb=xg,yb=yg;
		for(int i=0;(i<250)&&(yb>0)&&(yb<=yg)&&(xb<=xw)&&(xb>=0);i++)
		{	
			ballpos[i][0]=yb;
			float m=(x-xg)/(y-yg);   			
			xb=m*(yb-y)+x;	
			yb-=0.1/sqrt(m*m+1);				
			ballpos[i][1]=xb;
			countballpositions++;	
		}
		
		#include"draw.h"
		return 0;
	}

	else if(x>26.3&&y>14.5)
	{
		//exit2.Draw();
		Game.RenderText(Position(xc,yc),"Exiting...Please Wait...",Red,Black);
		sleep(2);
		Game.Close();
	}
	else
	{
		return 1;
	}
}

