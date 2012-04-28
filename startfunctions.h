void startfunctions()
{
	

	int i=0;
	while(i<ballcount)
	{
		draw(ballpos,ballcount,'b',i);
		i++;
		
		if(collide(xb,yb,2,4,2.25)==0)
		{
			//playgame
			flag=1;
			break;
		}
		if(collide(xb,yb,6.5,4,2.25)==0)
		{
			//highscore
			flag=2;
			break;
		}
		if(collide(xb,yb,11,4,2.25)==0)
		{
			//highscore
			flag=3;
			break;
		}
		if(collide(xb,yb,15.5,4,2.25)==0)
		{
			//instructions
			flag=4;
			break;
		}
		if(collide(xb,yb,20,4,2.25)==0)
		{
			//credits
			flag=5;
			break;
		}
		if(collide(xb,yb,24.5,4,2.25)==0)
		{
			//exit
			flag=6;
			break;
		}
		else
		flag=0;
	}
	
	if(flag==1)   // Start Game
	{
		Game.Close();
		playgame();
	}
	if(flag==2)		//High Score
	{
		Game.Close();
		Game.Open();
		background.Draw();
		highscorei.SetPosition(Position(12,0));
		highscorei.Draw();
		for(i=0;i<10;i++)
		{	
			char printscore[200];
			sprintf(printscore,"%d : %s   :   %d",i+1,highscoreuser[i],highscore[i]);//making highscore appear one by one with a small time gap
			//for(float k=0;k<14;k+=1)
			//{
				Game.RenderText(Position(14,i+4.5),printscore,Yellow,Black);
				usleep(500000);
				//background.Draw();
			//}
		}
		Game.RenderText(Position(14,15.5),"*******************************************************************************************************************************************",Black,Black);
		sleep(2);
		Game.Close();
		start();
	}
	
	if(flag==3)		//Choose Level
	{
		//Game.RenderText(Position(14,7.5),"Go To Terinal To Type...",Red,Black);
		//Game.Close();
		/*cout<<"Enter Level (0-10)";
		cin>>level;
		while(level<0&&level>10)
		{
			cout<<"You Entered Wrong level";
			cout<<"Re-Enter Level(0-10)";
			cin>>level;
		}
		level=1+level/10;*/

		levelw.Open();//opening level window
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
		levelw.SetMouseClickCallback(clicklevel);//calling clicklevel function
	}
	if(flag==4)		//Instruction To play
	{
		Game.Close();
		Game.Open();
		background.Draw();
		next.Draw();
		exit1.Draw();
		instructioni.Draw();
		Game.SetMouseClickCallback(clickinstruction);//drawing instruction images
	}
	if(flag==5)		//Credits
	{
			
		Game.Close();
		Game.Open();

		background.Draw();
		crediti.SetPosition(Position(12,0));
		
		Game.RenderText(Position(14,0),"CREDITS",Black,Black);
		crediti.Draw();
		for(float ycredit=21;ycredit>9;ycredit-=0.5)		//writing credits which come from bottom moving above
		{
			background.Draw();
			Game.RenderText(Position(12,0.1),"CREDITS",Black,Black);
			crediti.Draw();
			
			Game.RenderText(Position(14,ycredit-5),"Teachin Assistant :                              ",Yellow,Black);
			Game.RenderText(Position(14,ycredit-4),"Shashank Rachamalla",Red,Black);
			Game.RenderText(Position(14,ycredit-3),"Team Members :                                ",Yellow,Black);
			Game.RenderText(Position(14,ycredit-2),"Mayank Meghwanshi",Red,Black);
			Game.RenderText(Position(14,ycredit-1),"Mrinal Mishra",Red,Black);
			Game.RenderText(Position(14,ycredit),"Mohammad Saqib Alam",Red,Black);
			Game.RenderText(Position(14,ycredit+1),"Monimoy Bujarbaruah",Red,Black);
			Game.RenderText(Position(14,ycredit+2),"Mohammad Anees",Red,Black);
			Game.RenderText(Position(14,ycredit+3),"Mukesh Chauhan",Red,Black);
			Game.RenderText(Position(14,ycredit+4),"Jalpa",Red,Black);
			Game.RenderText(Position(14,ycredit+4),"**************************************************************************************************************************************",Red,Black);
			
			usleep(300000);
		}
			sleep(2);
			Game.Close();
			start();
			
		
	}
	if(flag==6)		//Exit
	{
		Game.Close();//exit button to close game
	}
			
}
