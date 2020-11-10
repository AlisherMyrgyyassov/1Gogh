#include <cmath>
#include <iostream>
using namespace std;
int bufx=40, bufy=40;
void draw(int x,int y)
{
  double b=acos(1-((pow(x,2)+pow(y,2))/24200))*57.3;
  double a=(180-b)/2 + acos(x/sqrt(pow(x,2)+pow(y,2)))*57.3;
  if(x==0 && y==0)
  {
  	cout<<"a="<<0;
  	cout<< " b="<<0;   
  }
  else
  {
  	cout<<"a="<<a;
  	cout<< " b="<<b << " x"<<x<<" "<<"y"<<y<<endl; 	
  }	
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
      } 
  }
  if(x<bufx)
  {
      for(int i=bufx;i>=x;i--)
      {
        draw(i,(y-bufy)/(x-bufx)*i + (bufy*x-bufx*y)/(x-bufx));
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
      }
    }
    else
    {
      for(int i=bufy; i>=y; i--)
      {
        draw(x,i);
      }        
    }
  }  
  bufx=x;
  bufy=y; 
}
int main()
{
int x1, y1;
cin>>x1>>y1;
SmartDraw(x1,y1);
cin>>x1>>y1;
SmartDraw(x1,y1);	
}
