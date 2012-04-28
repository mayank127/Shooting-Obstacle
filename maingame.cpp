#include <assert.h>
#include "ezwin.h"
#include<cstring>
#include<cstdio>
#include<stdlib.h>
#include<GraphicPosition.h>
#include<cmath>
#include"circle.h"
#include<time.h>
#include"SimpleWindow.h"
#include"bitmap.h"
#include"rect.h"
#include"ellipse.h"
#include"Alert.h"




//Functions*************************************************
void playgame();
int MouseClick(const Position &p);
int mousestart();
void ball(float , float);
void obstacle();
void cursor();
void draw(float pos[][2],int count,char object,int i);
int collide(float,float,float,float,float);
void click();
void start();
int MouseClick(const Position&);
void startfunctions();
void sort();
int clicklevel(const Position &p);
int clickinstruction(const Position &p);
//**********************************************************

//Global Variables*******************************************
Position p;
float xclick=14,yclick=0,xcursor,ycursor,xc,yc,xg,yg,xgf,ygf,length,xb,yb,xo=0,yo=0,xw=28.0,yw=15.0,obspos[1000][2],ballpos[250][2],level=1;
int check=1,flag=0,flag1=0,startflag=1,countinst=0;
int ballcount=0,obstaclecount=0,j=0,score=0,obstaclemissed=0,highscore[11];
char username[100]="Player 1",welcome[120],highscoreuser[11][100],textscore[40];
FILE *fp,*fp2;


//xclick,yclick mouse click  
//xcursor,ycursor cursor position
//xc,yc center of window
//xg,yg xgf,ygf coordinates of starting and endpoints of gun
//length distance between cursor position and (xg,yg)
//xb,yb coordinates of ball
//xo,yo coordinates of obstcle
//xw,yw size of window
//obspos matrix containing x,y coordinates of obstacle
//ballpos matrix containing position of ball
//level to decide difficulty level of game
//ballcount,obstaclecount number of elements in respective matrixes

//************************************************************


//Windows*******************************************************

SimpleWindow Game("Star Wars", xw,yw,Position(0.0,5.0));
SimpleWindow levelw("Select Level",7,3,Position(9,2));

//BitMaps*************************************************************
BitMap background(Game);
BitMap ballimage(Game);
BitMap exit1(Game);
BitMap exit2(Game);
BitMap obstacleimage(Game);
BitMap starti(Game);
BitMap highscorei(Game);
BitMap instructioni(Game);
BitMap leveli(Game);
BitMap crediti(Game);
BitMap exiti(Game);
BitMap starwar(Game);
BitMap next(Game);
BitMap explode(Game);
BitMap inst1(Game);
BitMap inst2(Game);
//Other Programm Include files********************************
#include"playgame.h"
#include"cursor.h"
#include"ball.h"
#include"Mousestart.h"
#include"draw.h"
#include"obstacle.h"
#include"collide.h"
#include"click.h"
#include"start.h"
#include"startfunctions.h"
#include"sort.h"
#include"clicklevel.h"
#include"clickinstruction.h"
//******************************************************************



//Main Program******************************************************************************************************************
int ApiMain()
 {
	
	
	cout<<"*******************Welcome To  The Game****************************"<<endl;
	cout<<"Enter Your Name ";
	cin>>username;
	sprintf(welcome,"Welcome To The Game %s",username);	
	Game.Open();																			
	

	AlertWindow("Loading","Your Game Will Load In A While..");
	Game.RenderText(Position(14,7.5),"Loading Game Please Wait....!!!",Red,White);
	Game.RenderText(Position(14,3.5),"Star Wars",Red,Black);
	RectangleShape r(Game,Position(14,8.5),Black,28,1);
	r.Draw();
	
	//loading all images*****************************************************************************************************
	background.Load("images/background.xpm");
	assert(background.GetStatus() == BitMapOkay);
	background.SetPosition(Position(0,0));
	background.Draw();
	Game.RenderText(Position(14,3.5),"Star Wars",Red,Black);
	Game.RenderText(Position(15,7.5),"Loading Game Please Wait....!!!",Red,Black);
	r.Draw();
	RectangleShape fill(Game,Position(1,8.5),White,2,1);
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	ballimage.Load("images/ball.xpm");
	assert(ballimage.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(3,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	exit1.Load("images/exitunpressed.xpm");
	assert(exit1.GetStatus() == BitMapOkay);
	exit1.SetPosition(Position(26.3,14.5));
	inst1.Load("images/instruction1.xpm");
	assert(inst1.GetStatus() == BitMapOkay);
	inst1.SetPosition(Position(6,2));
	fill.SetPosition(Position(5,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading1....",Black,White);
	
	exit2.Load("images/exitpressed.xpm");
	assert(exit2.GetStatus() == BitMapOkay);
	exit2.SetPosition(Position(26.3,14.5));
	inst2.Load("images/instruction2.xpm");
	assert(inst2.GetStatus() == BitMapOkay);
	inst2.SetPosition(Position(6,2));
	fill.SetPosition(Position(7,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	obstacleimage.Load("images/obstacle.xpm");
	assert(obstacleimage.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(9,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	starti.Load("images/start.xpm");
	assert(starti.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(11,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	highscorei.Load("images/highscores.xpm");
	assert(highscorei.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(13,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	leveli.Load("images/level.xpm");
	assert(leveli.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(15,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	instructioni.Load("images/instructions.xpm");
	assert(instructioni.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(17,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	crediti.Load("images/credit.xpm");
	assert(crediti.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(19,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	exiti.Load("images/quit.xpm");
	assert(exiti.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(21,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	starwar.Load("images/starwars.xpm");
	assert(starwar.GetStatus() == BitMapOkay);
	fill.SetPosition(Position(23,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	explode.Load("images/explode.xpm");
	assert(explode.GetStatus() == BitMapOkay);
	explode.SetPosition(Position(-4,-4));
	fill.SetPosition(Position(25,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	
	next.Load("images/next.xpm");
	assert(next.GetStatus() == BitMapOkay);
	next.SetPosition(Position(24,14.4));
	fill.SetPosition(Position(27,8.5));
	fill.Draw();
	Game.RenderText(Position(14,8.5),"Loading....",Black,White);
	AlertWindow("Welcome",welcome);


	//Reading from highscore.txt and storing them in an array.
	fp=fopen("HighScore.txt","r");
	char input[120];
	for(int i=0;i<10;i++)
	{
		fgets(input,120,fp);
		sscanf(input,"%s%d",highscoreuser[i],&highscore[i]);
	}
	fclose(fp);
	
	start();  			//Calling start function

	
	/*RectangleShape NewGame(Game,Position(14,4.5),Blue,8,2);
	NewGame.Draw();
	Game.RenderText(Position(14,4.5),"New Game",Blue,Red);
	mouse();*/
	//playgame();
	


	
	return 0;
}

