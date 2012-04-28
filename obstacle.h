//obstacle funtion randomly generates obstacle pos matrix on different functions
 
void obstacle()
{
	
		int func=0;
		srand(time(0));
		func=random()%5;//selecting random function
		int countobstaclepositions=0;
		//float obspos[1000][2];
		int i=0;
		srand(time(0));
		float r=2.5;
		r=random()%5+2.5;//selecing random y origin
		switch(func)
		{
		
		case 0://sin function
			for(xo=0.0;xo<28;xo+=0.1,i++)
			{
				yo = sin(xo*3.14159);
				yo = -3*yo+r;       
				countobstaclepositions++;
				if(yo>0)
				{
					obspos[i][0]=xo;
					obspos[i][1]=yo;
					//Game.RenderText(Position(xc,yc),"sin",Red,Black);
				}
			}
			break;
		case 1://floor function
			for(xo=0.0;xo<28;xo+=0.1,i++)
			{
				yo=-floor(xo/4)+7.5;
				countobstaclepositions++;
				if(yo>0)
				{
					obspos[i][0]=xo;
					obspos[i][1]=yo;
					//Game.RenderText(Position(xc,yc),"floor",Red,Black);
				}
			}	
			break;
		case 2://straight line function
			for(xo=0.0;xo<28;xo+=0.1,i++)
			{
				yo=r;
				countobstaclepositions++;
				if(yo>0)
				{
					obspos[i][0]=xo;
					obspos[i][1]=yo;
					//Game.RenderText(Position(xc,yc),"straight",Red,Black);
				}
			}	
			break;
		case 3://zig zag function
			for(xo=0.0;xo<28;xo+=0.1,i++)
			{
				if(xo<4)
				{
					yo=xo+r;
					
				}
				else if(xo<8)
				{
					yo=-xo+r+8;
				}
				else if(xo<12)
				{
					yo=xo+r-8;
				}
				else if(xo<16)
				{
					yo=-xo+r+16;
				}
				else if(xo<20)
				{
					yo=xo+r-16;
				}
				else if(xo<24)
				{
					yo=-xo+r+24;
				}
				else
				{
					yo=xo+r-24;
				}
				countobstaclepositions++;
				if(yo>0)
				{
					obspos[i][0]=xo;
					obspos[i][1]=yo;
					//Game.RenderText(Position(xc,yc),"zig-zag",Red,Black);
				}
			}
			break;
		case 4://parabolic function
			for(xo=0.0;xo<28;xo+=0.1,i++)
			{
				yo=-(xo-14)*(xo-14)/25+r;
				countobstaclepositions++;
				if(yo>0)
				{
					obspos[i][0]=xo;
					obspos[i][1]=yo;
					//Game.RenderText(Position(xc,yc+2),"quadratic",Red,Black);
				}
			}
		
				
		}
		obstaclecount=countobstaclepositions;//number of elements in formed matrix
		//draw(obspos,obstaclecount,'o');
}	
