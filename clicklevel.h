
// click file for level window.
int clicklevel(const Position &p)
{
	float x=p.GetXDistance();//getting x,y coordinates of click.
	float y=p.GetYDistance();
	level=1;float i=0;
	RectangleShape bar(levelw,Position(3.5,1),White,6,1);//drwaing the rectangular bar which get filled when clicked.
	bar.Draw();


	//choosing different values of level on clicking on specific area.
	if(y>0.5&&y<1.5)
	{
		if(x>0.45&&x<1.05)
		{
			level=1.1;
			i=0.75;
			
		}
		if(x>1.05&&x<1.65)
		{
			level=1.2;
			i=1.35;
		}
		if(x>1.65&&x<2.25)
		{
			level=1.3;
			i=1.95;
		}
		if(x>2.25&&x<2.85)
		{
			level=1.4;
			i=2.55;
		}
		if(x>2.85&&x<3.45)
		{
			level=1.5;
			i=3.15;
		}
		if(x>3.45&&x<4.05)
		{
			level=1.6;
			i=3.75;
		}
		if(x>4.05&&x<4.65)
		{
			level=1.7;
			i=4.35;
		}
		if(x>4.65&&x<5.25)
		{
			level=1.8;
			i=4.95;
		}
		if(x>5.25&&x<5.85)
		{
			level=1.9;
			i=5.55;
		}
		if(x>5.85&&x<6.55)
		{
			level=2.0;
			i=6.15;
		}
	}
	//int c=1;
	//draing fill bar in the white bar drawn.
	for(float k=0.75;k<=i;k+=0.6)
	{
		RectangleShape block(levelw,Position(k,1),Green,0.5,0.9);
		block.Draw();
		
		char levelchar[10];
		sprintf(levelchar,"%.0f",(level*10)-10);
		levelw.RenderText(Position(k,1),levelchar,Red,Green);
	}
	if(y>1.75&&y<2.75)
	{
		if(x>0.5&&x<3)
		{
			levelw.Close();//clicking on ok will save level value and go back to main menu.
			//start();
		}
		if(x>4&&x<6.5)
		{
			level=1;
			levelw.Close();//clicking on cancel will close the level window and make level to zeroth level.
			//start();
		}
	}
}	
			
