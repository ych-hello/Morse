#include "Arduino.h"

void morse(int a);
void dot();
void dash();
void w_space();
void s_space();
int _a;
int _dottime;
int letter[28][4]={

{1,2,0,0},{2,1,1,1},{2,1,2,1},{2,1,1,0},{1,0,0,0},{1,1,2,1},{2,2,1,0},{1,1,1,1},{1,1,0,0},

{1,2,2,2},{2,1,2,0},{1,2,1,1},{2,2,0,0},{2,1,0,0},{2,2,2,0},{1,2,2,1},{2,2,1,2},{1,2,1,0},

{1,1,1,0},{2,0,0,0},{ 1,1,2,0},{1,1,1,2},{1,2,2,0},{2,1,1,2},{2,1,2,2},{2,2,1,1 },{3,0,0,0},{4,0,0,0}
};

void setup()
{
  morse(8);
  Serial.begin(9600);
  
}

void loop()
{
  while(Serial.available() > 0 )
  {
  int ascii=Serial.read();
 
  ascii=ascii-65;

  for(int i=0;i<4;i++)
  {
    if(letter[ascii][i]==1)
    dot();
    else if(letter[ascii][i]==2)
    dash();
    else if(letter[ascii][i]==3)
    c_space();
    else if(letter[ascii][i]==4)
    w_space();
  }
  
  delay(3000);
  }
}

void morse(int a)
{
	pinMode(a,OUTPUT);
	_a=a;
	_dottime=250;
}

void dot()
{
	digitalWrite(_a,HIGH);
	delay(_dottime);
	digitalWrite(_a,LOW);
	delay(_dottime);
}

void dash()
{
	digitalWrite(_a,HIGH);
	delay(_dottime*4);
	digitalWrite(_a,LOW);
	delay(_dottime);
}

void c_space()
{
	digitalWrite(_a,LOW);
	delay(_dottime*3);
}

void w_space()
{
	digitalWrite(_a,LOW);
	delay(_dottime*7);
}
