#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>

FILE *fp;
int f , key ,k;
struct BEATS
{
    int octave;
    char *note;
    int Delay;

};

struct BEATS e;

int frequency(int note, int octave){
    int table[][9] =  {
		{16,32,65,130,261,523,1046,2093,4186},
		{17,34,69,138,277,554,1108,2217,4434},
		{18,36,73,146,293,587,1174,2349,4698},
		{19,38,77,155,311,622,1244,2489,4978},
		{20,41,82,164,329,659,1318,2637,5274},
		{21,43,87,174,349,698,1396,2793,5587},
		{23,46,92,185,369,739,1479,2959,5919},
		{24,49,98,196,392,783,1567,3135,6271},
		{25,51,103,207,415,830,1661,3322,6644},
		{27,55,110,220,440,880,1760,3520,7040},
		{29,58,116,233,466,932,1864,3729,7458},
		{30,61,123,246,493,987,1975,3951,7902}
    };

    return table[note][octave];

}

int keyconverter(struct BEATS e1){

    if(!strncmp(e1.note,"C",2))
	key = 0;
    else if(!strncmp(e1.note , "C#",2))
	key =1;
    else if(!strncmp(e1.note , "D",2))
	key =2;
    else if(!strncmp(e1.note , "D#",2))
	key =3;
    else if(!strncmp(e1.note , "E",2))
	key =4;
    else if(!strncmp(e1.note , "F",2))
	key =5;
    else if(!strncmp(e1.note , "F#",2))
	key =6;
    else if(!strncmp(e1.note , "G",2))
	key =7;
    else if(!strncmp(e1.note , "G#",2))
	key =8;
    else if(!strncmp(e1.note , "A",2))
	key =9;
    else if(!strncmp(e1.note , "A#",2))
	key =10;
    else if(!strncmp(e1.note , "B" ,2))
	key =11;

    return key;
}


void coffin(){
	fp = fopen("COFFIN.DAT" , "r");
	textcolor(GREEN);
	cprintf("ASTRONOMIA (COFFIN)");

	while(fscanf(fp, "%d %s %d" , &e.octave, e.note, &e.Delay) != EOF){
		 k = keyconverter(e);
		 f = frequency(k,e.octave);

		  sound(f);
		  delay(e.Delay);

		
	  }
	nosound();
	

}

void doreamon(){
	fp = fopen("BEATS2.DAT" , "r");
	textcolor(BLUE);
	cprintf("DOREAMON THEME SONG");

	while(fscanf(fp, "%d %s %d" , &e.octave, e.note, &e.Delay) != EOF){
		 k = keyconverter(e);
		 f = frequency(k,e.octave);

		 sound(f);
		 delay(e.Delay);
	}
	nosound();

}

void harryp(){
	fp = fopen("HP.DAT" , "r");
	textcolor(BROWN);
	cprintf("HARRY POTTER THEME SONG");

	while(fscanf(fp, "%d %s %d" , &e.octave, e.note, &e.Delay) != EOF){
		 k = keyconverter(e);
		 f = frequency(k,e.octave);


		 sound(f);
		 delay(e.Delay);
	}
	nosound();

}


int main(){
	int y = 10,x = 25;
	int ch;
	printf("\n-----------------------------------------------------------------------------");
	printf("\n                        MUSIC IN C USING TURBOC++                           ");
	printf("\nENTER YOUR CHOICE");
	printf("\n1.MUSIC THEME 1  ");
	printf("\n2.MUSIC THEME 2  ");
	printf("\n3.MUSIC THEME 3  ");
	printf("\n4.EXIT  ");
	scanf("\n%d" , &ch);
	while(ch != 4){
	 switch(ch){
	   case 1 : y+=2;
		    gotoxy(x,y);
		    coffin();
		    break;
	   case 2 : y+=2;
		    gotoxy(x,y);
		    doreamon();
		    break;
	   case 3 : y+=2;
		    gotoxy(x,y);
		    harryp();
		    break;
	   default : printf("\nOOPS !  WRONG CHOICE");
		     break;
	 }

	   printf("\nENTER YOUR CHOICE AGAIN  ");
	   scanf("%d" , &ch);
	}
	clrscr();

   getch();
   return 0;
}