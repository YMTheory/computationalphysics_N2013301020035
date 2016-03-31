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
 //  tmpX();
//   tmpY();
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


Projectile::Plot()  //Vector->Array and plot in ROOT
{
  int n;
  n = x.size();
 // cout<<n<<endl;
  double *X = new double[n];
  double *Y = new double[n];
  double *VX = new double[n];
  double *VY = new double[n];

double X1,Y1,VX1,VY1;
VX1 = vx[n-1];
X1 = x[n-1]+vx[n-1]*dt;
VY1 = vy[n-1]-g*dt;
Y1 = y[n-1]+vy[n-1]*dt;

//cout<<"Hey!"<<X1<<" "<< Y1<<endl;

  for(int j=0;j<n-1;j++)
{if(j<n-2){
 X[j] = x[j];
 Y[j] = y[j];
 VX[j] = vx[j];
 VY[j] = vy[j];
}
else
{
X[j] =  x[n-1]-(x[n-1]-X1)/(y[n-1]-Y1)*y[n-1];
Y[j] = 0;
}
//cout<<X[j]<<" "<<Y[j]<<endl;
}




   TCanvas *ym = new TCanvas("projectile","projectile",1200,1000);
   TGraph *g1=new TGraph(n,X,Y);
   g1->SetTitle("Projectile");
   g1->GetXaxis()->SetTitle("x");
   g1->GetYaxis()->SetTitle("y");
   g1->GetXaxis()->SetLimits(0,6);
   g1->SetMarkerSize(2);
//   g1->SetLineWidth(1.5);
   g1->Draw("AP");

return;
}

/*
Projectile::xToArray()
{
 
 n = x.size();
 double *X = new double[n];
 double X1,Y1,VX1,VY1;
 VX1 = vx[n-1];
 X1 = x[n-1]+vx[n-1]*dt;
 VY1 = vy[n-1]-g*dt;
 Y1 = y[n-1]+vy[n-1]*dt;
  for(int j=0;j<n-1;j++)
{if(j<n-2){
 X[j] = x[j];
}
else
{
X[j] =  x[n-1]-(x[n-1]-X1)/(y[n-1]-Y1)*y[n-1];
}
//cout<<X[j]<<endl;
}
return;
}
*/


/***************************************************************************************************************************************/



/*********************************************new class derived from the Projectile class**********************************************/

class ResisProjectile : public Projectile  //with resistance situation
{
public:
void Nextstep(int i){

  float g = 9.8;
  double dt = 0.001;
  double b2m = 0.4;
  double v = sqrt(vx[i]*vx[i]+vy[i]*vy[i]);

  vx.push_back(vx[i]-b2m*v*vx[i]*dt);
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt-b2m*dt*v*vy[i]);
  y.push_back(y[i] + vy[i]*dt);
 // cout<<x[i]<<"    "<<y[i]<<endl;
//if(y[i]>1.2){cout<<i<<" "<<x[i]<<" "<<y[i]<<endl;}
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
  double b2m = 0.04;
  int y0 = 10000;
  double v = sqrt(vx[i]*vx[i]+vy[i]*vy[i]);
  vx.push_back(vx[i]-b2m*v*vx[i]*dt*exp(-y[i]/y0));
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt-b2m*dt*v*vy[i]*exp(-y[i]/y0));
  y.push_back(y[i] + vy[i]*dt);

 // cout<<x[i]<<"    "<<y[i]<<endl;
//if(y[i]>1.2){cout<<i<<" "<<x[i]<<" "<<y[i]<<endl;}
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
  double b2m = 0.04;
  float a = 0.0065;
  double T0 = 290;
  float alpha = 2.5;
  double v = sqrt(vx[i]*vx[i]+vy[i]*vy[i]);
 /* if(y[i]>=0){
  vx[i+1] = vx[i]-b2m*v*vx[i]*dt*pow((1-a*y[i]/T0),alpha);
  x[i+1] = x[i]+vx[i]*dt;
  vy[i+1] = vy[i]-g*dt-b2m*dt*v*vy[i]*pow((1-a*y[i]/T0),alpha);
  y[i+1] = y[i] + vy[i]*dt;}
  else
  {x[i+1]=x[i];
   y[i+1]=vx[i+1]=vy[i+1]=0;}
 // cout<<x[i]<<"    "<<y[i]<<endl;
//if(y[i]>1.2){cout<<i<<" "<<x[i]<<" "<<y[i]<<endl;}
*/
  vx.push_back(vx[i]-b2m*v*vx[i]*dt*pow((1-a*y[i]/T0),alpha));
  x.push_back(x[i]+vx[i]*dt);
  vy.push_back(vy[i]-g*dt-b2m*dt*v*vy[i]*pow((1-a*y[i]/T0),alpha));
  y.push_back(y[i] + vy[i]*dt);
return;
}
};



void projectile()
{

Projectile cannon;
cannon.Init(2,1,5,1);
int i =0;
do
{
cannon.Nextstep(i);
i++;}
while(cannon.y[i]>=0);
int n;
n = cannon.x.size();
cout<<n<<endl;
//cannon.xToArray();
//cout<<X[12]<<endl;

 double *X = new double[n];     //I hven't solve how to visit parameters in the function of class,so this part is too complicated! -_-!
 double *Y = new double[n];
 double X1,Y1,VX1,VY1;
 VX1 = cannon.vx[n-1];
 X1 = cannon.x[n-1]+cannon.vx[n-1]*cannon.dt;
 VY1 = cannon.vy[n-1]-cannon.g*cannon.dt;
 Y1 = cannon.y[n-1]+cannon.vy[n-1]*cannon.dt;
 cout<<X1<<endl;
  for(int j=0;j<n-1;j++)
{if(j<n-2){
 X[j] = cannon.x[j];
 Y[j] = cannon.y[j];
}
else
{
X[j] =  cannon.x[n-1]-(cannon.x[n-1]-X1)/(cannon.y[n-1]-Y1)*cannon.y[n-1];
Y[j] = 0;
}
//cout<<X[j]<<endl;
}



   TCanvas *ym = new TCanvas("projectile","projectile",1200,1000);
   TGraph *g1=new TGraph(n,X,Y);
   g1->SetTitle("Projectile");
   g1->GetXaxis()->SetTitle("x");
   g1->GetYaxis()->SetTitle("y");
   g1->SetMarkerColor(2);
//   g1->SetLineWidth(1.5);
   g1->Draw("AP");
  // g2->Draw("Psame");
//cannon.Plot();

return;
}




