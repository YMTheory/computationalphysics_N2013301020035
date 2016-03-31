#include<iostream>
#include<math.h>
#include"TMath.h"
#include"TGraph.h"
#include<cmath>
using namespace std;


/******************************First we define a class to describe projectile motion****************************************************/

class Projectile //no resistance situation
{
public:
  float g = 9.8;
  double dt =0.01;

  vector<double> x;   //Use vector for I don't know the size of array before
  vector<double> y;
  vector<double> vx;
  vector<double> vy;



   Init(double a,double b,double c,double d);
   Nextstep();
   Intersection();
   Plot();

};


Projectile::Init(double a,double b,double c,double d) //initial condition
{
 x.push_back(a);
 y.push_back(b);
 vx.push_back(c);
 vy.push_back(d);

 return;
}

Projectile::Nextstep(int i)  //how to get next position and velocity with Euler method
{

    float g = 9.8;
    double dt = 0.001;
  vx.push_back(vx[i]);
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt);
  y.push_back(y[i] + vy[i]*dt);
 // cout<<x[i]<<" "<<y[i]<<endl;

return;
} 

Projectile::Intersection()    //Obtain the intersection to the ground
{
    float g = 9.8;
    double dt = 0.001;

 double X1,Y1;
 X1 = x.back()+vx.back()*dt;
 Y1 = y.back()+vy.back()*dt;
 x.push_back(X1);
 y.push_back(Y1);
return;
}



Projectile::Plot()   //Plot in ROOT
{

   int n;
   n=x.size();
   TCanvas *ym = new TCanvas("projectile","projectile",1200,1000);
   TGraph *g1=new TGraph(n,&x[0],&y[0]);
   g1->SetTitle("Projectile");
   g1->GetXaxis()->SetTitle("x");
   g1->GetYaxis()->SetTitle("y");
   g1->GetXaxis()->SetLimits(0,2200);
   g1->GetYaxis()->SetLimits(0,500);
   g1->SetMarkerSize(2);
   g1->Draw("AP");

return;
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

Projectile cannon0;
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




//cannon.Plot();
return;
}




