void start()
{	
	Game.Open();			//opening window
	background.Draw();		//drwaing background

	Game.RenderText(Position(14,1),welcome,Red,Black);
	RectangleShape head(Game,Position(14,1),Black,10,1.5);
	head.Draw();								//Writing welcome note on top of main screen.

	/*for(float i=2;i<28;i+=4.5)
	{
		EllipseShape e(Game,Position(i,4),Red,4,4);
		e.Draw();
	}
	Game.RenderText(Position(2,4),"Start",Red,Black);
	Game.RenderText(Position(6.5,4),"HighScore",Red,Black);
	Game.RenderText(Position(11,4),"Level",Red,Black);
	Game.RenderText(Position(15.5,4),"Instruction",Red,Black);
	Game.RenderText(Position(20,4),"Credits",Red,Black);
	Game.RenderText(Position(24.5,4),"Quit",Red,Black);
	*/

	//for entrance of star wars image from left.
	for (float i=-28;i<=1;i++)
	{
		starwar.SetPosition(Position(i,6.5));
		starwar.Draw();
		Game.RenderText(Position(14,1),welcome,Red,Black);
		usleep(100000);
	}	
	//drawing all images on main screen using usleep to give microsecond sleep in program.
	usleep(400000);

	starti.SetPosition(Position(0,2));
	starti.Draw();
	Game.RenderText(Position(14,1),welcome,Red,Black);
	usleep(400000);

	highscorei.SetPosition(Position(4.5,2));
	highscorei.Draw();
	Game.RenderText(Position(14,1),welcome,Red,Black);
	usleep(400000);

	leveli.SetPosition(Position(9,2));
	leveli.Draw();
	Game.RenderText(Position(14,1),welcome,Red,Black);
	usleep(400000);

	instructioni.SetPosition(Position(13.5,2));
	instructioni.Draw();
	Game.RenderText(Position(14,1),welcome,Red,Black);
	usleep(400000);

	crediti.SetPosition(Position(18,2));
	crediti.Draw();
	Game.RenderText(Position(14,1),welcome,Red,Black);
	usleep(400000);

	exiti.SetPosition(Position(22.5,2));
	exiti.Draw();
	Game.RenderText(Position(14,1),welcome,Red,Black);


	startflag=1;
	Game.RenderText(Position(14,1),welcome,Red,Black);

	
	
		
	mousestart(); 				//calling mouse start function.
	//ball(xclick,yclick);
}
