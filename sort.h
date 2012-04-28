
//sort function to sort highscore
void sort()
{
	for(int i=0;i<11;i++)
	{
		
			if(highscore[i]<highscore[10])//this function takes 11 entries in highscore matrix from which 10 are previous top 10 and 11th is current score which is sorted if 11th is larger than any of previous  it will automatically come up
			{
				int temp;
				char tempa[200];
				temp=highscore[i];
				highscore[i]=highscore[10];
				highscore[10]=temp;
				strcpy(tempa,highscoreuser[i]);

				strcpy(highscoreuser[i],highscoreuser[10]);
				strcpy(highscoreuser[10],tempa);
			}
		
	
	}
	fp=fopen("HighScore.txt","w");
	for(int i=0;i<10;i++)
	{
		char pr[100];
		//printf("%s %d\n",highscoreuser[i],highscore[i]);
		sprintf(pr,"%s %d\n",highscoreuser[i],highscore[i]);
		fputs(pr,fp);					//updating file with new top 10
		
	}
	fclose(fp);
	AlertWindow("Saved","High Score Saved");
	
}
