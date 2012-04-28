

//Not In Use Now
void click()
{

	if(xclick>10&&xclick<18&&yclick>3.5&&yclick<5.5)
	{
		//Game.Close();
		//Game.Open();
		//playgame();
	}
	if(xclick>26.3&&yclick>14.5)
	{
		//exit2.Draw();
		Game.RenderText(Position(xc,yc),"Exiting...Please Wait...",Red,Black);
		sleep(2);
		Game.Close();
	}
}
