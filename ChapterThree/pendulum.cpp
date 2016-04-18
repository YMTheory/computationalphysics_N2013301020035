#include<iostream>
#include<math.h>
#include"TMath.h"
#include"TGraph.h"
#include<cmath>
#include"TPaveText.h"
using namespace std;

class Pendulum
{
public:  //meeting some problems with vectors
  double theta[2000];
  double omega[2000];
  double time[2000];
 
  Init(double a,double b);
  NextstepEuler();
  NextstepEC();
  NextstepRKEC();
  NextstepEREC();
  NextstepREEC();
  Plot();
};

Pendulum::Init(double a,double b)
{
  theta[0] = a;
  omega[0] = b;
  time[0] = 0;
return;
}

Pendulum::NextstepEuler(int i) //with Euler-Cromer Method
{
  double dt = 0.01;
  theta[i] = theta[i-1]+omega[i-1]*dt;
  omega[i] = omega[i-1]-dt*pow(theta[i-1],3);
  time[i] = i*dt;
return;
}

Pendulum::NextstepEC(int i) //Both with Euler-Cromer Method
{
  double dt = 0.01;
  omega[i] = omega[i-1]-dt*pow(theta[i-1],3);
  theta[i] = theta[i-1]+omega[i]*dt;
  time[i] = i*dt;

return;
}

Pendulum::NextstepRKEC(int i) //Both with Runge_kutta Method and Euler_Cromer;
{
  double dt = 0.01;
  double f1,f2,f3,f4,F1,F2,F3,F4;
  f1 = -pow(theta[i-1],3);
  f2 = -pow((theta[i-1] + 0.5*dt*f1),3);
  f3 = -pow((theta[i-1] + 0.5*dt*f2),3);
  f4 = -pow((theta[i-1] + dt*f3),3);
  omega[i] = omega[i-1]+dt*(f1+2*f2+2*f3+f4)/6;
  F1 = omega[i];
  F2 = omega[i] + 0.5*dt*F1;
  F3 = omega[i] + 0.5*dt*F2;
  F4 = omega[i] + dt*F3;
  theta[i] = theta[i-1]+dt*(F1+2*F2+2*F3+F4)/6;
  time[i] = i*dt;
  
 // cout<<dt*(f1+2*f2+2*f3+f4)/6<<" "<<dt*(F1+2*F2+2*F3+F4)/6<<endl;
return;
}

Pendulum::NextstepEREC(int i)
{
  double dt = 0.01;
  omega[i] = omega[i-1]-pow(theta[i-1],3)*dt;
  double F1,F2,F3,F4;
  F1 = omega[i];
  F2 = omega[i] + 0.5*dt*F1;
  F3 = omega[i] + 0.5*dt*F2;
  F4 = omega[i] + dt*F3;
  theta[i] = theta[i-1]+dt*(F1+2*F2+2*F3+F4)/6;
  time[i] = i*dt;
  
return;
}

Pendulum::NextstepREEC(int i)
{
  double dt = 0.01;
  double f1,f2,f3,f4;
  f1 = -pow(theta[i-1],3);
  f2 = -pow((theta[i-1] + 0.5*dt*f1),3);
  f3 = -pow((theta[i-1] + 0.5*dt*f2),3);
  f4 = -pow((theta[i-1] + dt*f3),3);
  omega[i] = omega[i-1]+dt*(f1+2*f2+2*f3+f4)/6;
  theta[i] = theta[i-1]+omega[i]*dt;
  time[i] = i*dt;

return;
}

Pendulum::Plot()   //Plot in ROOT
{

   TCanvas *ym = new TCanvas("pendulum","pendulum",1200,1000);
   TGraph *g1=new TGraph(2000,time,theta);
   g1->SetTitle("Oscillatory Motion");
   g1->GetXaxis()->SetTitle("time/s");
   g1->GetYaxis()->SetTitle("theta");
  // g1->GetXaxis()->SetLimits(0,2200);
   //g1->GetYaxis()->SetLimits(0,500);
   g1->SetMarkerSize(0.5);
   g1->Draw("APL");

return;
}

void pendulum()
{
/*  double anal[2000];
  double time[2000];
  for(int i;i<2000;i++)
  {
    double dt = 0.01;
    anal[i] = 1/sqrt(9.8)*sin(dt*i*sqrt(9.8));
    time[i] = i*dt;
  }
*/
  Pendulum p1;
  p1.Init(0,1);
  for(int i=1;i<2000;i++)
  {p1.NextstepEC(i);}
 // p1.Plot();
//   cout<<p1.theta.back()<<" "<<p1.omega.back()<<endl;}
 // p1.Plot();
  Pendulum p2;
  p2.Init(0,1);
  for(int i=1;i<2000;i++)
  {p2.NextstepRKEC(i);}
//  p2.Plot(); 
  
  Pendulum p3;
  p3.Init(0,1);
  for(int i=1;i<2000;i++)
  {p3.NextstepEREC(i);}

  Pendulum p4;
  p4.Init(0,1);
  for(int i=1;i<2000;i++)
  {p4.NextstepREEC(i);}

 /* double diff2 = 0;
  for(int i=0;i<2000;i++)
  { 
    diff2 += (p2.theta[i]-anal[i])*(p2.theta[i]-anal[i]);
  }
    cout<<diff2/2000<<endl;
 */
   TCanvas *ym = new TCanvas("pendulum","pendulum",1200,1000);
   TGraph *g1=new TGraph(2000,p1.time,p1.theta);
   TGraph *g2=new TGraph(2000,p2.time,p2.theta);
   TGraph *g3=new TGraph(2000,p3.time,p3.theta);
   TGraph *g4=new TGraph(2000,p4.time,p4.theta);
  // TGraph *g0=new TGraph(2000,time,anal);
   g1->SetTitle("Oscillatory Motion");
   g1->GetXaxis()->SetTitle("time/s");
   g1->GetYaxis()->SetTitle("theta");
//   g1->GetXaxis()->SetLimits(0,2200);
//   g1->GetYaxis()->SetLimits(0,500);
   g1->SetLineWidth(0.1);
   g2->SetLineWidth(0.1);
   g3->SetLineWidth(0.1);
   g4->SetLineWidth(0.1);
   g1->SetLineColor(1);
   g2->SetLineColor(2);
   g3->SetLineColor(3);
   g4->SetLineColor(4);
  // g0->SetLineColor(5);
   g1->Draw("APL");
   g2->Draw("PLsame");
   g3->Draw("PLsame");
   g4->Draw("PLsame");
  // g0->Draw("PLsame");
   TLegend *legend = new TLegend(.75,.80,.95,.95);
   legend->AddEntry(g1,"Euler");
   legend->AddEntry(g2,"RK");
   legend->AddEntry(g3,"Euler-RK");
   legend->AddEntry(g4,"RK-Euler");
  // legend->AddEntry(g0,"Analytic");
   legend->Draw();


  double diff12 = 0;
  for(int i=0;i<2000;i++)
  { 
    diff12 += (p1.theta[i]-p2.theta[i])*(p1.theta[i]-p2.theta[i]);
  }
    cout<<diff12<<endl;

return;
}
