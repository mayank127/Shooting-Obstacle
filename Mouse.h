//intitial mouse function which wah not used in end program, but logic used differently at 2-3 places

int mouse()
{
	
	
		Game.SetMouseClickCallback(MouseClick);
		//sleep(3);
		//clickcount++;
		return  0;
	
}
int MouseClick(const Position &p)
{
	xclick=p.GetXDistance();
	yclick=p.GetYDistance();
	char c[100];
	sprintf(c,"click(%f,%f)",xclick,yclick);
	Game.RenderText(Position(0,0),c,Red,Black);
	//clickcount++;
	//click();
	return 0;
}

