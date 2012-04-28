void playgame()
{	
	Game.Open();
	startflag=0;
	

	
	
	//background.SetPosition(Position(0,0));  
	//background.Draw();     // drawing background
	//exit1.SetPosition(Position(xw-1.7,yw-0.5));
	//exit1.Draw();
	//exit2.SetPosition(Position(xw-1.7,yw-0.5));
	

	Position center =Game.GetCenter();
	xc = center.GetXDistance();
	yc = center.GetYDistance();
	xg = xc;
	yg = yc+5;
	//RectangleShape base(Game,Position(xg,yg),Black,28.0,0.5);
	//base.ClearBorder();
	//base.Draw();
	//RectangleShape exit(Game,Position(26.5,14.5),Red,3,1);
	exit1.Draw();
	//Game.RenderText(Position(26.5,14.5),"Exit",Black,Red);
	//Game.RenderLine(Position(0,yc+5),Position(28.0,yc+5),Black,0.5);
	
	cursor();					//calling cursor function to give cursor positions
	ball(xcursor,ycursor);		//using cursor position to make ball array
	while(1)					//infinite loop till break
	{	
		
		

		sprintf(textscore,"Score = %d Ballmissed = %d Level = %.1f",score,obstaclemissed,level*10-10);		//printing score level and obstacle missed
		Game.RenderText(Position(5,yw-0.5),textscore,Red,Black);
		obstacle();				//calling obstacle function to make matrix of obstacle
		obstaclemissed++;		//obstacle missed counter increased.
		int i=0;
		//usleep(500000);
		while(check)
		{
		

			long int timei=GetMilliseconds();//noting time i and time f to caluclate dt 
			long int timef=GetMilliseconds();
			 int dt=0;
			while(dt<10)//for 10 milliseconds cursor function is executed which will move the gun
			{	

				cursor();
				int timef=GetMilliseconds();
				dt=timef-timei;
				Game.RenderText(Position(5,yw-0.5),textscore,Red,Black);
				//char dta[100];
				//sprintf(dta,"time %d",dt);
				//Game.RenderText(Position(xc,yc-2),dta,Red,Black);
				
			}
			if(xcursor>25&&xcursor<28&&ycursor>14&&ycursor<15)
				{
					flag1=1;
					break;
				}
			while(dt<25*level)//for 25*level-10 milliseconds ball is moved
			{	
				draw(ballpos,ballcount,'b',j);
				j++;
				explode.Draw();
				if(j==ballcount)
				{	
					cursor();
					//mouse();
					ball(xcursor,ycursor);
					//ball(xclick,yclick);
					j=0;
				}
				Game.RenderText(Position(5,yw-0.5),textscore,Red,Black);
				int timef=GetMilliseconds();
				dt=timef-timei;
				//char dta[100];
				//sprintf(dta,"time %d",dt);
				//Game.RenderText(Position(xc,yc-2),dta,Red,Black);
				

			}
			while(dt<45*level*level)//for45*level*level-25*level seconds obstacle is moved
			{

				
				draw(obspos,obstaclecount,'o',i);
				i++;
				explode.Draw();
				int timef=GetMilliseconds();
				dt=timef-timei;
				//char dta[100];
				//sprintf(dta,"time %d",dt);
				//Game.RenderText(Position(xc,yc-2),dta,Red,Black);
				exit1.Draw();
				
			}
			if(collide(xb,yb,xo,yo,0.955)==0)//checking if collision occured if yes than obstacle missed is decremented and new obstacle and ball is drawn
			{	
				//Game.RenderText(Position(xo,yo),"C O L L I S I O N",Red,Black);
				explode.SetPosition(Position(xo-1,yo-1));
				explode.Draw();
				cursor();
				ball(xcursor,ycursor);
				j=0;
				score+=10;
				if(score%50==0)
				{
					level+=0.1;
				}
				obstaclemissed--;

				break;
			}
		}
		check=1;

		//char textscore[20];
		//sprintf(textscore,"Score = %d ballmissed = %d",score,obstaclemissed);
		Game.RenderText(Position(5,yw-0.5),textscore,Red,Black);
		if(obstaclemissed==3||flag==0)//if obstacle missed equals 3 or user hovers his mouse over exit button it will close the main window and score will be saved and sorted
		{

			obstaclemissed=0;
			if(flag==0)
			Game.RenderText(Position(xc,yc),"You Missed Three Obstacles...!!!G A M E O V E R",Black,Red);
			if(flag==1)
			Game.RenderText(Position(xc,yc),"You Exitted...!!!G A M E O V E R",Black,Red);
			exit2.Draw();
			Game.RenderText(Position(5,yw-0.5),textscore,Red,Black);
			char congo[200];
			sprintf(congo,"Congratulations...%s...!!!You Scored %d",username,score);
			sleep(2);
			AlertWindow("Congratulations",congo);
			strcpy(highscoreuser[10],username);
			highscore[10]=score;
			sort();
			Game.Close();

			
		}
	}	
}
