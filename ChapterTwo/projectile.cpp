#include<iostream>
#include<math.h>
#include"TMath.h"
#include"TGraph.h"
#include<cmath>
#include"TPaveText.h"
using namespace std;


/******************************First we define a class to describe projectile motion****************************************************/

class Projectile //no resistance situation
{
public:
  float g = 9.8;
  double dt =0.01;

  double X1,Y1,X2,X3;  

  vector<double> x;   //Use vector for I don't know the size of array before
  vector<double> y;
  vector<double> vx;
  vector<double> vy;
  vector<double> distance;


   Init(double a,double b,double c,double d);
   Nextstep();
   Intersection();
   Plot();
   MaxDistance();
   Shoot();
   Delete();

};


Projectile::Init(double a,double b,double c,double d) //initial condition
{
 x.push_back(a);
 y.push_back(b);
 vx.push_back(c*cos(d));
 vy.push_back(c*sin(d));
 //cout<<x.back()<<" "<<y.back()<<" "<<vx.back()<<" "<<vy.back()<<endl;
 return;
}

Projectile::Nextstep()  //how to get next position and velocity with Euler method
{

    float g = 9.8;
    double dt = 0.001;
  vx.push_back(vx.back());
  x.push_back(x.back()+vx.back()*dt);
  vy.push_back(vy.back()-g*dt);
  y.push_back(y.back() + vy.back()*dt);
 // cout<<x[i]<<" "<<y[i]<<endl;

return;
} 

Projectile::Intersection()    //Obtain the intersection to the ground
{
    float g = 9.8;
    double dt = 0.001;

 X1 = x.back()+vx.back()*dt;
 Y1 = y.back()+vy.back()*dt;
 X2 = X1-(X1-x.back())/(Y1-y.back())*Y1;
 x.push_back(X1-(X1-x.back())/(Y1-y.back())*Y1);
 y.push_back(0);
 //distance.push_back(x.back());
 //double max = 0;
// if(max < distance.back()){max = distance.back();}
// cout<<max<<endl;
 
return;
}



Projectile::Plot()   //Plot in ROOT
{

   int n;
   n=x.size();
   TCanvas *ym = new TCanvas("projectile","projectile",1200,1000);
   TGraph *g1=new TGraph(n,&x[0],&y[0]);
   g1->SetTitle("Projectile");
   g1->GetXaxis()->SetTitle("x/m");
   g1->GetYaxis()->SetTitle("y/m");
  // g1->GetXaxis()->SetLimits(0,2200);
   //g1->GetYaxis()->SetLimits(0,500);
   g1->SetMarkerSize(2);
   g1->Draw("AP");

return;
}

Projectile::MaxDistance()
{

  int m;
  m = distance.size();
  for(int j=0;j<m;j++)
  {
  double tmp=0;
  int num=0;
  cout<<distance[j]<<endl;
   if(tmp<distance[j])
   {tmp = distance[j];
    num = j;}
  }
cout<<tmp<<" "<<num<<endl;
return;
}


Projectile::Shoot(double a)
{
    float g = 9.8;
    double dt = 0.001;

 X1 = x.back()+vx.back()*dt;
 Y1 = y.back()+vy.back()*dt;
 X3 = X1-(X1-x.back())/(Y1-y.back())*Y1+a*(X1-x.back())/(Y1-y.back());
 x.push_back(X3);
 y.push_back(a);

return:

}

Projectile::Delete()
{
   int n;
   n = x.size();
   for(int i=0;i<n;i++)
   {x.pop_back();
    y.pop_back();
    vx.pop_back();
    vy.pop_back();}
}

/***************************************************************************************************************************************/



/*********************************************new class derived from the Projectile class**********************************************/

class ResisProjectile : public Projectile  //with resistance situation
{
public:
void Nextstep(int i){

  float g = 9.8;
  double dt = 0.001;
  double b2m = 0.00004;
  double v = sqrt(vx[i]*vx[i]+vy[i]*vy[i]);

  vx.push_back(vx[i]-b2m*v*vx[i]*dt);
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt-b2m*dt*v*vy[i]);
  y.push_back(y[i] + vy[i]*dt);
return;
}
};


/*********************************************new class derived from the Projectile class***********************************************/

class IsothProjectile:public Projectile  //isothermal model correction
{

public:
void Nextstep(int i){

  float g = 9.8;
  double dt = 0.001;
  double b2m = 0.00004;
  int y0 = 10000;
  double v = sqrt(vx[i]*vx[i]+vy[i]*vy[i]);

  vx.push_back(vx[i]-b2m*v*vx[i]*dt*exp(-y[i]/y0));
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt-b2m*dt*v*vy[i]*exp(-y[i]/y0));
  y.push_back(y[i] + vy[i]*dt);

return;
}
};

/****************************************new class derived from the Projectile class*****************************************************/

class AdiProjectile:public Projectile  //adiabatic model correction
{

public:
void Nextstep(int i){

  float g = 9.8;
  double dt = 0.001;
  double b2m = 0.00004;
  float a = 0.0065;
  double T0 = 290;
  float alpha = 2.5;
  double v = sqrt(vx[i]*vx[i]+vy[i]*vy[i]);
  
  vx.push_back(vx[i]-b2m*v*vx[i]*dt*pow((1-a*y[i]/T0),alpha));
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt-b2m*dt*v*vy[i]*pow((1-a*y[i]/T0),alpha));
  y.push_back(y[i] + vy[i]*dt);
return;
}
};



void projectile()
{

/****************************************************Four different motions*******************************************************************/
/*Projectile cannon0;
ResisProjectile cannon1;
IsothProjectile cannon2;
AdiProjectile cannon3;
cannon0.Init(0,0,200,200);
cannon1.Init(0,0,200,200);
cannon2.Init(0,0,200,200);
cannon3.Init(0,0,200,200);
int i0 =0;
do
{
cannon0.Nextstep(i0);
i0++;}
while(cannon0.y[i0]>=0);
int i1 =0;
do
{
cannon1.Nextstep(i1);
i1++;}
while(cannon1.y[i1]>=0);
int i2 =0;
do
{
cannon2.Nextstep(i2);
i2++;}
while(cannon2.y[i2]>=0);
int i3 =0;
do
{
cannon3.Nextstep(i3);
i3++;}
while(cannon3.y[i3]>=0);

cannon0.Intersection();
cannon1.Intersection();
cannon2.Intersection();
cannon3.Intersection();

int n0,n1,n2,n3;
n0 = cannon0.x.size();
n1 = cannon1.x.size();
n2 = cannon2.x.size();
n3 = cannon3.x.size();


   TCanvas *ym = new TCanvas("projectile","projectile",1200,1000);
   TGraph *g0=new TGraph(n0,&cannon0.x[0],&cannon0.y[0]);
   TGraph *g1=new TGraph(n1,&cannon1.x[0],&cannon1.y[0]);
   TGraph *g2=new TGraph(n2,&cannon2.x[0],&cannon2.y[0]);
   TGraph *g3=new TGraph(n3,&cannon3.x[0],&cannon3.y[0]);
   g0->SetTitle("Projectile");
   g0->GetXaxis()->SetTitle("x/m");
   g0->GetYaxis()->SetTitle("y/m");
   g0->GetYaxis()->SetRangeUser(0,2500);
   g0->SetMarkerColor(1);
   g1->SetMarkerColor(2);
   g2->SetMarkerColor(3);
   g3->SetMarkerColor(4);
  // g2->SetMarkerStyle(21);
 //  g1->SetLineWidth(1.5);
   g0->Draw("AP");
   g1->Draw("Psame");
   g2->Draw("Psame");
   g3->Draw("Psame");
   TLegend *legend = new TLegend(.75,.80,.95,.95);
   legend->AddEntry(g0,"ideal projectile");
   legend->AddEntry(g1,"projectile with air resistance");
   legend->AddEntry(g2,"isothermal model");
   legend->AddEntry(g3,"adiabatic");
   legend->Draw();
*/

/********************************************Maximum Distance firing angle********************************************************************/
/*
Projectile ball;
for(int j=0;j<500;j++)
{ 
  
//cout<<j<<endl;
  ball.Init(0,0,360,j*0.001*3.1415926);       //fixing the firing velocity and change firing angle for the maximum distance with error in  0.001*Pi but this way is too slow!

  int i =0;
  do
 {ball.Nextstep();}
  while(ball.y.back()>=0);
 ball.Intersection();
 ball.distance.push_back(ball.X2);
 double max=0;
 double angle = 0;
 if(max<ball.X2)
 {max=ball.X2;
  angle=j*0.001*3.141592653;
 }
}
cout<<max<<" "<<angle<<endl;
//ball.MaxDistance();
//cannon.Plot();*/


/************************************************************Shoot a given target************************************************************/

//double targetx,targety;
/*cout<<"Set x position of the target:"<<endl;
cin>>targetx;
cout<<"Set y position of the target:"<<endl;
cin>>targety;*/
//targety = 500;

//Projectile shell;
//cannon.Init(0,0,200,1.56765);

//float scanning(double a,double b)
//{
/*
int max=-10;
double anglemax=-10;
double velocitymax=-10;
vector<int> Count;
vector<double> Angle;
vector<double> Velocity;
double a=97;
while(1){
if(a>96 && a<103){
double b=0.6981;
 while(1){
 if(b>0.6980 && b<0.8727)
{double targety = 5;
double angle[10];
double velocity[10];
vector<double> distribution;
TRandom3 r1,r2;
for(int i=0;i<10;i++)
{
velocity[i] = r1.Gaus(a,5);
angle[i]=r2.Gaus(b,0.05);
//cout<<angle[i]<<" "<<velocity[i]<<endl;
}

 int count=0;
for(int i=0;i<10;i++)
{
  for(int j=0;j<10;j++)
  {
    Projectile *shell;
    shell = new Projectile;
  //  cout<<velocity[j]<<" "<<angle[i]<<endl;
    shell->Init(0,0,velocity[j],angle[i]);
   // cout<<shell->x.back()<<" "<<shell->y.back()<<" "<<shell->vx.back()<<" "<<shell->vy.back()<<endl;

    double tmp = -10;
do
{
shell->Nextstep();
if(tmp>=shell->y.back())
{break;}
tmp = shell->y.back();
//cout<<shell.x.back()<<shell.y.back()<<endl;
}while(shell->y.back()>0);
do
{shell->Nextstep();}
while(shell->y.back()>targety);
shell->Shoot(targety);
//cout<<shell.x.back()<<endl;
    distribution.push_back(shell->X3);
//    cout<<j<<"  "<<endl;
//    shell.Delete();
//    shell->Plot();
//    delete shell;
if(shell->X3>900 && shell->X3<1100)
{count++;}
//cout<<shell->X3<<endl;
delete shell;
}
}
cout<<count<<endl;
if(count>max){
max = count;
anglemax = b;
velocitymax = a;}

Angle.push_back(b);
Velocity.push_back(a);
Count.push_back(count);

}
else{break;}
b+=0.1;
}
}
else{break;}
a+=2;}
cout<<max<<" "<<anglemax<<" "<<velocitymax<<endl;

  int n;
  n = Count.size();
  cout<<n<<endl;
  TCanvas *c1 = new TCanvas("distribution","distribution",1200,1000);
  TGraph2D *dt = new TGraph2D();
  for(int k=0;k<n;k++)
  {int x;
   double y,z;
  x = Angle[k];
  y = Velocity[k];
  z = Count[k];
  dt->SetPoint(k,x,y,z);}
  dt->Draw("APL");
   

   TPaveText *pt = new TPaveText(0.6,0.7,0.98,0.98,"brNDC");
   pt->SetFillColor(18);
   pt->SetTextAlign(12);
   pt->AddText("velocity(200,5)");
   pt->AddText("angle(0.785398,0.1)");
   pt->Draw();

*/

/*******************************************************TEST*****************************************************************************/
/*double targetx,targety;
cout<<"Set x position of the target:"<<endl;
cin>>targetx;
cout<<"Set y position of the target:"<<endl;
cin>>targety;

Projectile cannon;
cannon.Init(0,0,200,0.785398);
double tmp;
do
{
cannon.Nextstep();
if(tmp>=cannon.y.back())
{break;}
tmp = cannon.y.back();
}while(cannon.y.back()>0);
do
{cannon.Nextstep();}
while(cannon.y.back()>500);
cannon.Shoot(500);
//cout<<cannon.X3<<endl;
//cannon.Plot();
double comp1,comp2,mid;
comp1 = cannon.X3;
if(cannon.X3>targetx)
{
   comp2 = 0;
   mid = (comp1+comp2)/2;
   if(mid ){mid = (comp1+comp2)/2;}
   
}
*/

TCanvas *c1 = new TCanvas("distribution","distribution",1200,1000);
double targety = 5;
double angle[10];
double velocity[10];
vector<double> distribution;
TRandom3 r1,r2;
for(int i=0;i<4;i++)
{
velocity[i] = r1.Gaus(200,5);
angle[i]=r2.Gaus(0.78,0.05);
//cout<<angle[i]<<" "<<velocity[i]<<endl;
}

 int count=0;
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    Projectile *shell;
    shell = new Projectile;
  //  cout<<velocity[j]<<" "<<angle[i]<<endl;
    shell->Init(0,0,velocity[j],angle[i]);
   // cout<<shell->x.back()<<" "<<shell->y.back()<<" "<<shell->vx.back()<<" "<<shell->vy.back()<<endl;
double tmp = -10;
do
{
shell->Nextstep();
if(tmp>=shell->y.back())
{break;}
tmp = shell->y.back();
//cout<<shell.x.back()<<shell.y.back()<<endl;
}while(shell->y.back()>0);
do
{shell->Nextstep();}
while(shell->y.back()>targety);
shell->Shoot(targety);
distribution.push_back(shell->X3);
int n;
n = shell->x.size();
if((i=0) && (j=0)){
TGraph *g1 = new TGraph(n,&shell->x[0],&shell->y[0]);
g1->Draw("APL");}
//if(shell->X3>900 && shell->X3<1100)
//{count++;}
delete shell;
}
}






return;
}




