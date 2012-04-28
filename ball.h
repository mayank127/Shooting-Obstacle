void ball(float x,float y)
{
	Position center =Game.GetCenter();//getting center of screen
	xc = center.GetXDistance();
	yc = center.GetYDistance();
	xg = xc;
	yg = yc+5;
	length=sqrt((x-xg)*(x-xg)+(y-yg)*(y-yg));//measuring length between clik position and gun point.
	xgf=(x-xg)/length+xg;
	ygf=(y-yg)/length+yg;
	if(y<yg)
	{	
		//Game.Erase(Position(xg-1.5,yg-1.5),3,3);
		//Game.RenderLine(Position(xgf,ygf),Position(xg,yg),Black,0.5);

		//background.Draw();
		//exit1.Draw();
		//Game.RenderLine(Position(xgf,ygf),Position(xg,	yg),Black,0.5);
		//base.Draw();
		//CircleShape ball(Game,Position(xgf,ygf),Yellow,0.5);
		//ball.ClearBorder();
		//ball.SetPosition(Position(xg,yg));
		
		/*char a[100];
		sprintf(a,"%f %f %f",x,y,length);
		Game.RenderText(Position(x,y),a,Red,Blue);*/
		
		//long timei=GetMilliseconds(),timef;
		//float ballpos[250][2];



		xb=xg,yb=yg;//initialising ball positions
		int countballpositions=0;
		for(int i=0;(yb>0)&&(yb<=yg)&&(xb<=xw)&&(xb>=0);i++)
		{	
			ballpos[i][1]=yb;
			float m=(x-xg)/(y-yg);   			
			xb=m*(yb-y)+x;	
			yb-=0.5/sqrt(m*m+1);		//changing y so that speed along lenth remains constant		
			ballpos[i][0]=xb;			//storing xb and yb in a matrix.
			countballpositions++;	
		}
		ballcount=countballpositions;	//number of elements in matrix corresponding to ball position.

		//draw(ballpos,ballcount,'b');
		
	}
	
	

	
}
