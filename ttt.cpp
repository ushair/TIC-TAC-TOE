#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define go gotoxy
#define p printf
main()
{
start:

int a[3][3]={3,4,5,6,3,4,5,6,7},pla,i,j,x,y,t,cn=0,co=0;
char c;
static int nod=0,nn=0,sc[2]={0,0};
nod++;
clrscr();
int driver=DETECT,mode;
initgraph(&driver,&mode,"..\\bgi");
line(410,1,410,600);
setbkcolor(0);
line(100,200,400,200);
line(100,300,400,300);
line(200,100,200,400);
line(300,100,300,400);
go(27,3);
p("TIC TAC TOE ");
go(30,4);
p("BY USHAIR ANSARI");
go(15,7);
p("1");
go(30,7);
p("2");
go(45,7);
p("3");
go(15,14);
p("4");
go(30,14);
p("5");
go(45,14);
p("6");
go(15,21);
p("7");
go(30,21);
p("8");
go(45,21);
p("9");
go(55,17);
p("RESULT");
go(55,18);
p("PLAYER 1- %d",sc[0]);
go(55,19);
p("PLAYER 2- %d",sc[1]);
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
re:
go(60,4);
pla=((i+j)%2+1);
p("ENTER PLAYER %d",pla);
go(53,5);
p("ENTER 1 TO 9 TO SELECT BOXES");
go(53,6);
t=getch();
t=t-48;
if(t==1)
{
x=0;
y=0;
goto play;
}
if(t==2)
{
x=1;
y=0;
goto play;
}
if(t==3)
{
x=2;
y=0;
goto play;
}
if(t==4)
{
sound(7);
x=0;
y=1;
goto play;
}
if(t==5)
{
x=1;
y=1;
goto play;
}
if(t==6)
{
x=2;
y=1;
goto play;
}
if(t==7)
{
x=0;
y=2;
goto play;
}
if(t==8)
{
x=1;
y=2;
goto play;
}
if(t==9)
{
x=2;
y=2;
goto play;
}
else
{
goto re ;
}

play:
if((a[x][y]==1)||(a[x][y]==2))
{
goto re;
}
if((a[x][y]!=1)&&(a[x][y]!=2))
{
if(pla==1)
{
sound(500);
delay(100);
nosound();
circle(100*x+100+50,100*y+100+50,50);
a[x][y]=pla;
co++;
}
if(pla==2)
{

sound(200);
delay(100);
nosound();
line(x*100+100,y*100+100,x*100+200,y*100+200);
line(x*100+100,y*100+200,x*100+200,y*100+100);
a[x][y]=pla;
co++;
}
go(59,23);
if((a[0][0]==a[1][0])&&(a[1][0]==a[2][0]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if((a[0][0]==a[0][1])&&(a[0][1]==a[0][2]))
{
p("PLAYER : - %d WINS",pla);

cn=1;
sc[pla-1]++;
}
if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if((a[1][0]==a[1][1])&&(a[1][1]==a[1][2]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if((a[2][0]==a[2][1])&&(a[2][1]==a[2][2]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if((a[2][0]==a[1][1])&&(a[1][1]==a[0][2]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if((a[0][2]==a[1][2])&&(a[1][2]==a[2][2]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if((a[0][1]==a[1][1])&&(a[1][1]==a[2][1]))
{
p("PLAYER : - %d WINS",pla);
cn=1;
sc[pla-1]++;
}
if(cn==1)
{
goto que;
}
if(co==9)
{
go(60,30);
p("DRAW");
nn++;
goto que;
}
}
}
}
que:
go(60,24);
p("Play again y/n ");
c=getch();
if((c=='y')||(c=='Y'))
{
goto start;
}
else if((c=='n')||(c=='N'))
{
goto end;
}
else goto que;
end:
closegraph();
p("   FINAL SCORE IS ");
p("  \n PLAYER 1 : %d",sc[pla-1]);
p("  \n PLAYER 2 : %d",nod-nn-sc[pla-1]);
p("  \n THANKS FOR PLAYING ");
getch();
}
