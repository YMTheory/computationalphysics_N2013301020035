#include<iostream>
#include<math.h>
#include"TMath.h"
#include"TGraph.h"
#include<cmath>
#include"TPaveText.h"
using namespace std;

class Pendulum
{
public:
  vector<double> theta;
  vector<double> omega;
  vector<double> time;
 
  Init(double a,double b);
  NextstepEuler();
  NextstepEC();
  NextstepRK();
  NextstepEK();
  NextstepRC();
  Plot();
};

Pendulum::Init(double a,double b)
{
  theta.push_back(a);
  omega.push_back(b);
  time.push_back(0);
return;
}

Pendulum::NextstepEuler() //with Euler-Cromer Method
{
  double dt = 0.01;
  theta.push_back(theta.back()+omega.back()*dt);
  omega.push_back(omega.back()-9.8*theta.back()*dt);
  time.push_back(time.back()+dt);
return;
}

Pendulum::NextstepEC() //Both with Euler-Cromer Method
{
  double dt = 0.01;
  omega.push_back(omega.back()-9.8*theta.back()*dt);
  theta.push_back(theta.back()+omega.back()*dt);
  time.push_back(time.back()+dt);
return;
}

Pendulum::NextstepRK() //Both with Runge_kutta Method;
{
  double dt = 0.01;
  double f1,f2,f3,f4,F1,F2,F3,F4;
  f1 = -theta.back()*theta.back()*theta.back();
  f2 = -pow((theta.back() - 0.5*dt*f1),3);
  f3 = -pow((theta.back() - 0.5*dt*f2),3);
  f4 = -pow((theta.back() - dt*f3),3);
  omega.push_back(omega.back()+dt*(f1+2*f2+2*f3+f4)/6);
  F1 = omega.back();
  F2 = omega.back() + 0.5*dt*omega.back();
  F3 = omega.back() + 0.5*dt*F2;
  F4 = omega.back() + dt*F3;
  theta.push_back(theta.back()+dt*(F1+2*F2+2*F3+F4)/6);
  time.push_back(time.back()+dt);
 // cout<<dt*(f1+2*f2+2*f3+f4)/6<<" "<<dt*(F1+2*F2+2*F3+F4)/6<<endl;
return;
}

Pendulum::NextstepEK()
{
  double dt = 0.01;
  omega.push_back(omega.back()-pow(theta.back(),3)*dt);
  double F1,F2,F3,F4;
  F1 = omega.back();
  F2 = omega.back() + 0.5*dt*omega.back();
  F3 = omega.back() + 0.5*dt*F2;
  F4 = omega.back() + dt*F3;
  theta.push_back(theta.back()+dt*(F1+2*F2+2*F3+F4)/6);
  time.push_back(time.back()+dt);
return;
}

Pendulum::NextstepRC()
{
  double dt = 0.01;
  double f1,f2,f3,f4;
  f1 = -theta.back()*theta.back()*theta.back();
  f2 = -pow((theta.back() - 0.5*dt*f1),3);
  f3 = -pow((theta.back() - 0.5*dt*f2),3);
  f4 = -pow((theta.back() - dt*f3),3);

  omega.push_back(omega.back()+dt*(f1+2*f2+2*f3+f4)/6);
  theta.push_back(theta.back()+omega.back()*dt);
  time.push_back(time.back()+dt);
return;
}

Pendulum::Plot()   //Plot in ROOT
{

   int n;
   n=theta.size();
   TCanvas *ym = new TCanvas("pendulum","pendulum",1200,1000);
   TGraph *g1=new TGraph(n,&time[0],&theta[0]);
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
  Pendulum p1;
  p1.Init(0.5,1);
  for(int i=0;i<2000;i++)
  {p1.NextstepEC();}
  p1.Plot();
//   cout<<p1.theta.back()<<" "<<p1.omega.back()<<endl;}
 // p1.Plot();
  Pendulum p2;
  p2.Init(0.5,1);
  for(int i=0;i<2000;i++)
  {p2.NextstepEuler();}
 
/*  Pendulum p3;
  p3.Init(0,1);
  for(int i=0;i<2000;i++)
  {p3.NextstepEK();}

  Pendulum p4;
  p4.Init(0,1);
  for(int i=0;i<2000;i++)
  {p4.NextstepRC();}

  double diff43 = 0;
  for(int i=0;i<2000;i++)
  { 
    diff43 += (p3.theta[i]-p4.theta[i])*(p3.theta[i]-p4.theta[i]);
  }
    cout<<diff43/2000<<endl;
 */
/*   TCanvas *ym = new TCanvas("pendulum","pendulum",1200,1000);
   TGraph *g1=new TGraph(2000,&p1.time[0],&p1.theta[0]);
   TGraph *g2=new TGraph(2000,&p2.time[0],&p2.theta[0]);
   TGraph *g3=new TGraph(2000,&p3.time[0],&p3.theta[0]);
   TGraph *g4=new TGraph(2000,&p4.time[0],&p4.theta[0]);
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
   g1->Draw("APL");
   g2->Draw("PLsame");
   g3->Draw("PLsame");
   g4->Draw("PLsame");
   TLegend *legend = new TLegend(.75,.80,.95,.95);
   legend->AddEntry(g1,"EC-EC");
   legend->AddEntry(g2,"RK-RK");
   legend->AddEntry(g3,"EC-RK");
   legend->AddEntry(g4,"RK-EC");
   legend->Draw();
*/

  double diff12 = 0;
  for(int i=0;i<2000;i++)
  { 
    diff12 += (p1.theta[i]-p2.theta[i])*(p1.theta[i]-p2.theta[i]);
  }
    cout<<diff12/2000<<endl;

return;
}
