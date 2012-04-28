
//click file for instruction window.
int clickinstruction(const Position &p)
{
	float x=p.GetXDistance();//getting x,y coordinates of click
	float y=p.GetYDistance();

	countinst++;//counter for odd even so can be switched between images
	if(x>24&&x<26&&y>14.4)
	{
		if(countinst%2==0)
		{
			inst1.Erase();//drawing and erasing instruction images and swapping between them.
			inst2.Draw();
		}
		else
		{
			inst2.Erase();
			inst1.Draw();
		}
	}
	if(x>26&&y>14.4)
	{
		Game.Close();//closing when clicked on exit button.
		start();//calling back start function
	}
}
