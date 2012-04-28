
//mouse click function for start window
int mousestart()
{
	
	
		Game.SetMouseClickCallback(MouseClick);
		
		return  0;
	
}
int MouseClick(const Position &p)
{
	xclick=p.GetXDistance();//getting coordinates of click
	yclick=p.GetYDistance();
	//char c[100];
	//sprintf(c,"click(%f,%f)",xclick,yclick);
	//Game.RenderText(Position(0,0),c,Red,Black);
	ball(xclick,yclick);//giving ball function click coordinates to make ballpos array  
	

	startfunctions();//calling startfunction in which different things will be executed accordingly
	
	
	return 0;
}

