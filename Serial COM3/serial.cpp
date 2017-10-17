#include<conio.h>
#include<stdio.h>
//#include<graphics.h>
#include<dos.h>
//#include<dir.h>
#include<stdlib.h>
#define COM1 0x3f8
#define SERIAL 0x14
#define SETUP 0x83
#define THR 0
#define LSR 5
#define RDR 0
#define THRRDY 0x20
#define MASK 0x7f
#define DTARDY 0x01
#define BGI "e:/sadat/tc-300/bgi"
void check_port(void);
void setup(void);
void bar(void);
void about_me(void);
void menu(void);
	//mouse handling functions
void init_mouse(void);
void show_mouse(void);
void hide_mouse(void);
int *left_click(void);
int *position_mouse(void);
union REGS regs;
void main (void)
{
 clrscr();
 int driver=DETECT,mode;
 int a;
 int *q,*t;
 int x,y,x1,y1;
 char file[20];
 struct ffblk ffblk1;
 FILE *fptr,*fptr2;
 char fc,rw;
 initgraph(&driver,&mode,BGI); //intiallizing graphics
 a=getmaxx();
 init_mouse(); //intiallizing mouse
 tag1:
 int m=0;
 menu();//menu
 setup(); //seting COM1
 show_mouse();//showing mouse
 while(!NULL)
 {
if((q=left_click())!=NULL)//detects left click
	{
	 x=q[0];
	 y=q[1];
	 if((x>=17) && (x<=100) && (y>=4) && (y<=18))
	 {
	hide_mouse();//hides mouse pointer
	setcolor(DARKGRAY);
	line(17,5,17,17);
	line(17,5,100,5);
	setcolor(WHITE);
	line(100,5,100,17);
	line(17,17,100,17);
	gotoxy(1,3);
	printf("Enter the name of the file to send with path:");
	scanf("%s",&file);
	if(findfirst(file,&ffblk1,FA_RDONLY)!=NULL)
		{
		 printf("\n\tTHE FILE DOES NOT EXISTS.");
		 printf("\n\n\tPress any key to continue........");
		 sound(3000);
		 sleep(1);
		 nosound();
		 getch();
		 goto tag1;
		}
	if((fptr=fopen(file,"rb"))==NULL)
		{
		 printf("\n\n\n\tUNABLE TO OPEN FILE");
		 printf("\n\n\n\tPress any key to continue........");
		 sound(3000);
		 sleep(1);
		 nosound();
		 getch();
		 goto tag1;
		}
		bar();
	while((fc=getc(fptr))!=EOF)
		{
		 outport(COM1+THR,fc);
		 delay(10);
		}
	outport(COM1+THR,fc);
	fclose(fptr);
	printf("\n\n\n\n\n\tFILE SUCESSFULLY SEND");
	printf("\n\nPress any key to continue........");
	sound(3000);
	sleep(1);
	nosound();
	getch();
	goto tag1;
	 }
	 else if((x>=135) && (x<=230) && (y>=4) && (y<=18))
	 {
	hide_mouse();
	setcolor(DARKGRAY);
	line(135,5,135,17);
	line(135,5,230,5);
	setcolor(WHITE);
	line(230,5,230,17);
	line(135,17,230,17);
	gotoxy(1,3);
	printf("Please wait ...........");
	bar();
	fptr2=fopen("recived_file.txt","wb");
	while(!NULL)
		{
		 if(inport(COM1+LSR) & DTARDY)
		 {
		rw=(inport(COM1+RDR) & MASK);
		if(rw==127)
			{
			 fclose(fptr2);
			 printf("\n\n\t\t FILE RECIEVED SUCCESSFULLY");
			 sound(3000);
			 sleep(1);
			 nosound();
			 printf("\n\tPress any key to continue.......");
			 getch();
			 goto tag1;
			}
		putc(rw,fptr2);
		 }
		}
	 }
	 else if((x>=260) && (x<=330) && (y>=4) && (y<=18))
	 {
	hide_mouse();
	setcolor(WHITE);
	line(260,17,330,17);
	line(330,5,330,17);
	setcolor(DARKGRAY);
	line(260,5,330,5);
	line(260,5,260,17);
	about_me();
	goto tag1;
	 }
	 else if((x>=440) && (x<=520) && (y>=4) && (y<=18))
	 {
	hide_mouse();
	setcolor(DARKGRAY);
	line(440,5,440,17);
	line(440,5,520,5);
	setcolor(WHITE);
	line(520,5,520,17);
	line(440,17,520,17);
	check_port();
	printf("\n\n\tPress any key to continue......");
	getch();
	goto tag1;
	 }
	 else if((x>=560) && (x<=a-30) && (y>=4) && (y<=18))
	 {
	hide_mouse();
	setcolor(DARKGRAY);
	line(550,5,550,17);
	line(550,5,a-30,5);
	setcolor(WHITE);
	line(a-30,5,a-30,17);
	line(550,17,a-30,17);
	delay(100);
	closegraph();
	exit(0);
	 }
	}
t=position_mouse();
x1=t[0];
y1=t[1];
if((x1>=17) && (x1<=100) && (y1>=4) && (y1<=18))
	{
	 if(m!=1)
	 {
	hide_mouse();
	setcolor(WHITE);
	line(17,5,17,17);
	line(17,5,100,5);
	setcolor(DARKGRAY);
	line(100,5,100,17);
	line(17,17,100,17);
	show_mouse();
	m=1;
	 }
	}
else if((x1>=135) && (x1<=230) && (y1>=4) && (y1<=18))
	{
	 if(m!=1)
	 {
	hide_mouse();
	setcolor(WHITE);
	line(135,5,135,17);
	line(135,5,230,5);
	setcolor(DARKGRAY);
	line(230,5,230,17);
	line(135,17,230,17);
	show_mouse();
	m=1;
	 }
	}
else if((x1>=260) && (x1<=330) && (y1>=4) && (y1<=18))
	{
	 if(m!=1)
	 {
	hide_mouse();
	setcolor(DARKGRAY);
	line(260,17,330,17);
	line(330,5,330,17);
	setcolor(WHITE);
	line(260,5,330,5);
	line(260,5,260,17);
	show_mouse();
	m=1;
	 }
	}
else if((x1>=440) && (x1<=520) && (y1>=4) && (y1<=18))
	{
	 if(m!=1)
	 {
	hide_mouse();
	setcolor(WHITE);
	line(440,5,440,17);
	line(440,5,520,5);
	setcolor(DARKGRAY);
	line(520,5,520,17);
	line(440,17,520,17);
	show_mouse();
	m=1;
	 }
	}
else if((x1>=550) && (x1<=a-30) && (y1>=4) && (y1<=18))
	{
	 if(m!=1)
	 {
	hide_mouse();
	setcolor(WHITE);
	line(550,5,550,17);
	line(550,5,a-30,5);
	setcolor(DARKGRAY);
	line(a-30,5,a-30,17);
	line(550,17,a-30,17);
	show_mouse();
	m=1;
	 }
	}
else if(m!=0)
	{
	 hide_mouse();
	 goto tag1;
	 m=0;
	}
 }
}
		 //to setup COM1 port
void setup(void)
{
 regs.h.ah=0;
 regs.x.dx=0;
 regs.h.al=SETUP;
 int86(0x14,?s,?s);
}
		 //performs port check
void check_port(void)
{
 regs.h.ah=1;
 regs.h.al='p';
 regs.x.dx=0;
 int86(0x14,?s,?s);
 gotoxy(1,3);
 if(regs.h.ah!=NULL)
 printf("Communication Error");
 else
 printf("Test completed successfully");
}
		 //menu
void menu(void)
{
 int a;
 cleardevice();
 a=getmaxx();
 setfillstyle(1,LIGHTGRAY);
 bar(0,0,a,20);
 setcolor(WHITE);
 line(0,1,a,1);
 line(0,20,a,20);
 line(121,5,121,17);
 line(531,5,531,17);
 line(251,5,251,17);
 setcolor(DARKGRAY);
 line(0,0,a,0);
 line(0,19,a,19);
 line(120,5,120,17);
 line(530,5,530,17);
 line(0,21,a,21);
 line(250,5,250,17);
 settextstyle(2,0,4);
 outtextxy(30,5,"SEND FILE");
 outtextxy(150,5,"RECIEVE FILE");
 outtextxy(270,5,"ABOUT ME");
 outtextxy(450,5,"CHECK PORT");
 outtextxy(570,5,"EXIT");
}
		 //loading bar
void bar(void)
{
 printf("\nInitializing connections........");
 for(int w=0; w<=300; w++)
 {
gotoxy(31,8);
printf("%d\%",((w*100)/300));
setfillstyle(1,LIGHTGRAY);
line(100+w,110,100+w,130);
delay(10);
 }
}
void about_me(void)
{
 setfillstyle(1,9);
 bar(0,21,639,500);
 setcolor(WHITE);
 settextstyle(3,0,4);
 outtextxy(140,100,"SADAT SAEED");
 settextstyle(3,0,2);
 outtextxy(150,150,"First year BS");
 outtextxy(150,200,"University of Karachi");
 outtextxy(150,250,"Pakistan");
 outtextxy(150,280,"sadatsaeed@hotmail.com"); 
 outtextxy(150,450,"Press any key to continue............");
 getch();
}
void init_mouse(void)
{
 regs.x.ax=0;
 int86(0x33,?s,?s);
 if((regs.x.ax)!=NULL)
 ("Mouse not installed\nPlease Oprate with keys.");
}
void show_mouse(void)
{
 regs.x.ax=1;
 int86(0x33,?s,?s);
}
void hide_mouse(void)
{
 regs.x.ax=2;
 int86(0x33,?s,?s);
}
int *left_click(void)
{
 int arr[2];
 regs.x.ax=3;
 int86(0x33,?s,?s);
 if((regs.x.bx)&1)
 {
arr[0]=regs.x.cx;
arr[1]=regs.x.dx;
return (&arr[0]);
 }
 else
 return (0);
}
int *position_mouse(void)
{
 int arr[2];
 regs.x.ax=3;
 int86(0x33,?s,?s);
 arr[0]=regs.x.cx;
 arr[1]=regs.x.dx;
 return(arr);
}
