#include<cstdio>
#include<iostream>
#include<conio.h>
#include<windows.h>
//alpha edition
//01-12-16 21:29
using namespace std;
int ttt[4][4]={9};
void clrscr()
{
  system("cls");
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void hline(int x1,int x2,int y)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y);
    printf("%c",196);//196
  }
}
void vline(int y1,int y2,int x)
{
  int i;
  for(i=y1;i<=y2;i++)
  {
    gotoxy(x,i);
    printf("%c",179);//179
  }
}
void rect(int x,int y)
{
  /*printing corners*/
  
  int x1,y1,x2,y2;
  x1=x-2;
  x2=x+2;
  y1=y-1;y2=y+1;
  gotoxy(x2,y1);
  printf("%c",191);
  gotoxy(x1,y2);
  printf("%c",192);
  gotoxy(x2,y2);
  printf("%c",217);
  gotoxy(x1,y1);
  printf("%c",218);
  /* printing lines */
  hline(x1+1,x2-1,y1);
  hline(x1+1,x2-1,y2);
  vline(y1+1,y2-1,x1);
  vline(y1+1,y2-1,x2);
}
void cross(int x,int y)
{
  /*printing corners*/
  
  int x1,y1,x2,y2;
  x1=x-2;
  x2=x+2;
  y1=y-1;y2=y+1;
  /*printing lines*/
  hline(x1,x2,y);
  vline(y1,y2,x);
}
void structure()
{
	hline(0,34,6);
	hline(0,34,14);
	vline(0,20,11);
	vline(0,20,23);
}
void input(int corr)
{
	int place,k=147;
	while(k==147)
	{
		k=1;
		gotoxy(0,24);
		cin>>place;
		if(place==1)
		{
			if(ttt[1][3]==9)
			ttt[1][3]=corr;
			else
			k=147;
		}
	else if(place==2)
	{
		if(ttt[2][3]==9)
		ttt[2][3]=corr;
		else
		k=147;
	}
	else if(place==3)
	{
		if(ttt[3][3]==9)
		ttt[3][3]=corr;
		else
		k=147;
	}
	else if(place==4)
	{
		if(ttt[1][2]==9)
		ttt[1][2]=corr;
		else
		k=147;
	}
	else if(place==5)
	{
		if(ttt[2][2]==9)
		ttt[2][2]=corr;
		else
		k=147;
	}
	else if(place==6)
	{
		if(ttt[3][2]==9)
		ttt[3][2]=corr;
		else
		k=147;
	}
	else if(place==7)
	{
		if(ttt[1][1]==9)
		ttt[1][1]=corr;
		else
		k=147;
	}
	else if(place==8)
	{
		if(ttt[2][1]==9)
		ttt[2][1]=corr;
		else 
		k=147;
	}
	else if(place==9)
	{
		if(ttt[3][1]==9)
		ttt[3][1]=corr;
		else
		k=147;
	}
	else
	k=1;
	}
}
void print()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			int x,y;
			x=5+12*(i-1);
			y=3+7*(j-1);
			if(ttt[i][j]==0)
			rect(x,y);
			else if(ttt[i][j]==1)
			cross(x,y);
		}
	}
}
int main()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			ttt[i][j]=9;
		}
	}
	structure();
	cout<<endl<<endl<<endl;
	int corr=0;
	for(int i=0;i<9;i++)
	{
		corr++;
		corr%=2;
		input(corr);
		print();
	}
	getch();
	return 0;
}
