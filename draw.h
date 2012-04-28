//a function to draw ball and obstacle taking respective arrays,array counter which is handled in playgame.h and object name i.e. ball('b') or obstacles('o')

void draw(float pos[][2],int count, char object,int i)
{
	if(object=='b')
	{
		//for(int i=0;i<count;i++)
		//{	
			//CircleShape ball(Game,Position(pos[i][0],pos[i][1]),Black,0.5);
			//ball.ClearBorder();
			//RectangleShape base(Game,Position(xg,yg),Black,28.0,0.5);
			//base.ClearBorder();
		
			ballimage.SetPosition(Position(pos[i][0],pos[i][1]));		//setting position of ball according to matrix and counter i
			//ball.Draw();
			ballimage.Draw();
			usleep(10000);	//sleep function so that it will appear for a while
			xb=pos[i][0];
			yb=pos[i][1];//saving positions in xb and yb so that they can be given to collide function for collision check 
			
			char b[100];
			sprintf(b,"ball pos(%d,%f,%f)",i,pos[i][0],pos[i][1]);
			Game.RenderText(Position(0,-1), b,Black,Black);

			if(startflag==1)			//flag if ball was used in play game or start.h if in strt than all the images have to be redrawn after drawing background
			{
				usleep(15000);
				background.Draw();
				starti.Draw();
				highscorei.Draw();
				leveli.Draw();
				instructioni.Draw();
				crediti.Draw();
				exiti.Draw();
				
			}
			//ball.Erase();
			//background.Draw();
			//exit1.Draw();
			//baseimage.Draw();
			//Game.RenderLine(Position(xgf,ygf),Position(xg,yg),Black,0.5);
		//}
	}
	if(object=='o')
	{	
		//for(float i=j;i<=count;i++)
		//{
			//CircleShape obstacle(Game,Position(pos[i][0],pos[i][1]),Red,1.5);
			//obstacle.ClearBorder();
			//obstacle.Draw();
			obstacleimage.SetPosition(Position(pos[i][0],pos[i][1]));			//setting position of obstacle from a\matrix and counter i.
			obstacleimage.Draw();
			usleep(15000);
			xo=pos[i][0];
			yo=pos[i][1];			//saving current position in xo yo so that it can be given in collide function 
			//mouse();
			
			
			char c[100];
			sprintf(c,"obstacle pos(%d,%f,%f)",i,pos[i][0],pos[i][1]);
			Game.RenderText(Position(0,-1),c,Black,Black);
			background.Draw();
			//obstacle.Erase();

			if(i==count)		//checking if first obstacle has passed if yes than setting counter back to 0.
			{
				i=0;
				check=0;
			}
			
		//}
	}
}
	

