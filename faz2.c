#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
char B[100][100]={'\0'};
void Handheldgame()
{
	int countsatr = 0 , countsoton = 0;
    int flag = 0,x,y,space;
    char h;
    for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            if (B[i][j]=='0')
            {
                x=i;
                y=j;
            }
            if (B[i][j]=='*')
            {
                flag = 1;
            }
        }
    }
	if (flag==0) 
	{
		return;
	}
	system("cls");
	for (int i=0;i<20;i++)
	{
		printf("%s\n",B[i]);
	}
	int ch1;
	char ch2;
    ch1 = getch();
    ch2 = 0;
    if (ch1 == 0xE0)
    {
        ch2 = getch();
        switch(ch2)
        {
            case 72 :
            {
                h='u';
                break;
            };
            case 75 :
            {
                h='l';
                break;
            };
            case 77 :
            {
                h='r';
                break;
            };
            case 80 :
            {
                h='d';
                break;
            };
        }
    }
	int l=0,kk=0;
	if (h=='u')
	{
		countsatr--;
	}
	if (h=='d') 
	{
		countsatr++;
	}
	if (h=='r')
	{
		countsoton++;
	}
	if (h=='l') 
	{
		countsoton--;
	}
	int bordX=x+countsatr , bordY=y+countsoton;
	if(B[bordX][bordY]!='#')
	{
		B[x][y]='1';
		if (bordY>=0&&bordY<20)
		{
			if(bordX>=0&&bordX<20)
			{
				B[bordX][bordY]='0';
			}
		} 
	}
	Handheldgame();
}
int main()
{
	FILE *ptf = fopen("C:\\Users\\amirps\\Desktop\\Testcase02.txt","r");
	int i = 0,j = 0;
	char ch1;
	fscanf(ptf,"%c",&ch1);
	for (;;)
	{
		char ch[10];
		for(;;)
		{
			fscanf(ptf,"%s",ch);
			if (j==0) 
			{
				B[i][j]=ch[4];
			}
			else 
			{
				B[i][j]=ch[3];
			}
			j++;
			if (ch[7]=='}') break;
		}
		if (ch[8]=='}') break;
		i++;
		j=0;
	}
	fclose(ptf);
	Handheldgame();
}
