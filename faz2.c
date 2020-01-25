#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

HANDLE hConsole;

char B[100][100];
void Handheldgame()
{
	int countsatr = 0 , countsoton = 0;
    int flag = 0,x,y,space;
    char h;
    for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            if (B[i][j]=='*')
            {
                flag = 1;
            }
			if (B[i][j]=='0')
            {
                x=i;
                y=j;
            }
        }
    }
	system("cls");
	for (int i=0;i<20;i++)
	{
		for (int j = 0; j < 10; j++){
			int p = 0;
			switch(B[i][j]){
				case '0': 
					p = 67;
					SetConsoleTextAttribute(hConsole, 14);
					break;
				case '1':
					p = ' ';
					SetConsoleTextAttribute(hConsole, 15);
					break;
				case '*' :
					p = 248;
					SetConsoleTextAttribute(hConsole, 12);
					break;
				case '#' :
					p = 178;
					SetConsoleTextAttribute(hConsole, 9);
			}
			printf ("%c",p);
			if (j==9) printf ("\n");
		}
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
	if (h=='u'&&x!=0)
	{
		countsatr--;
	}
	if (h=='d'&&x!=4) 
	{
		countsatr++;
	}
	if (h=='r'&&y!=9)
	{
		countsoton++;
	}
	if (h=='l'&&y!=0) 
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
		else 
		{
			x=0;
			y=0;
		}
	}
	if (flag==0) 
	{
		return;
	}
	Handheldgame();
}
int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char add[1000];
	printf ("ENTER FILE ADDRESS : ");
	scanf ("%s",add);
	FILE *ptf = fopen(add,"r");
	while (ptf==NULL)
	{
		printf ("YOUR ADDRESS WAS WRONG\n");
		printf ("ENTER FILE ADDRESS :");
		scanf ("%s",add);
		ptf = fopen(add,"r");
		break;
	}
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
