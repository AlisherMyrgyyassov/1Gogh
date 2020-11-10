#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
int bufx=40, bufy=40;
void setup()
{
  myservo1.attach(8); //shoulder
  myservo2.attach(9); //arm
  myservo3.attach(7); //pen
}
void penup()
{
  myservo3.write(90);
  delay (300);
}
void pendown()
{
  myservo3.write(120);
  delay (300);  
}
void draw(int x, int y)
{
  Serial.begin(9600);
  double b = acos(1 - ((pow(x, 2) + pow(y, 2)) / 24200)) * 57.3;
  double a = (180 - b) / 2 + acos(x / sqrt(pow(x, 2) + pow(y, 2))) * 57.3;
  if (x == 0 && y == 0)
  {
    myservo1.write(0);
    myservo2.write(180);
  }
  else
  {
    myservo1.write(a*0.85714);
    myservo2.write((180 - b)*1.00325);
  }
  Serial.println(a);
  Serial.println(b);
}
void SmartDraw(int x, int y)
{
  if(bufx!=x)
  {
  if(x>bufx)
  {
      for(int i=bufx;i<=x;i++)
      {
        draw(i,(y-bufy)/(x-bufx)*i + (bufy*x-bufx*y)/(x-bufx));
        delay(100);
      } 
  }
  if(x<bufx)
  {
      for(int i=bufx;i>=x;i--)
      {
        draw(i,(y-bufy)/(x-bufx)*i + (bufy*x-bufx*y)/(x-bufx));
        delay(100);
      }   
  } 
  }
  else
  {
    if(y>bufy)
    {
      for(int i=bufy; i<=y; i++)
      {
        draw(x,i);
        delay(100);
      }
    }
    else
    {
      for(int i=bufy; i>=y; i--)
      {
        draw(x,i);
        delay(100);
      }        
    }
  }  
  bufx=x;
  bufy=y; 
}
void picKor()
{
draw(40,40);
delay(500);
pendown();
delay(500);
SmartDraw(40,90);
delay(500);
SmartDraw(40,65);
delay(500);
SmartDraw(65,90);
delay(500);
SmartDraw(40,65);
delay(500);
SmartDraw(65,40);
delay(500);
penup();
}
void picStop()
{
  
}
void picCircle(int xc, int yc, int rc)
{
  for (int i=xc-rc; i<=xc+rc; i++)
  {
    SmartDraw(i, sqrt(pow(rc,2)-pow(i-xc,2))+yc);
    delay(300);
  }
    for (int i=xc+rc; i>=xc-rc; i--)
  {
    SmartDraw(i, -sqrt(pow(rc,2)-pow(i-xc,2))+yc);
    delay(300);
  }
}
void picDisabled()
{
  for (int i=38; i<=54; i++)
  {
    SmartDraw(i, sqrt(pow(26,2)-pow(i-64,2))+60);
    delay(300);
  }
    for (int i=88; i>=38; i--)
  {
    SmartDraw(i, -sqrt(pow(26,2)-pow(i-64,2))+60);
    delay(300);
    }
    bufx=51, bufy=88;
    SmartDraw(54,84);
    delay(500);
    SmartDraw(74,84);
    delay(500);
    SmartDraw(54,84);
    delay(500);
    SmartDraw(57,60);
    delay(500);
    SmartDraw(85,60);
    delay(500);
    SmartDraw(74,84);
    delay(500);
    SmartDraw(90,45);
    delay(500);
    penup();
    delay(100);
    draw(43,104);
    delay(300);
    pendown();
    delay(30);
    picCircle(53,104,10);
    delay(500);
  
}
void loop()
{
  penup();
  draw(60,60);
  delay(1500);
  pendown();
  picCircle(60,60,20);
}
