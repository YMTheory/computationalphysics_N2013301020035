#include<iostream>
#include<math.h>
#include"TMath.h"
#include"TGraph.h"
#include<cmath>
#include"TPaveText.h"
using namespace std;

void wave()
{

  double Y0[1001];
  double Y1[1001];
  double Y2[1001];
  double x[1001];
  float r = 1;

//cout <<Y0[0] << endl;
  const double p0=1;
  const double p1=0.3;
  const double p2=sqrt(0.0005);

  TF1 *f1 = new TF1("f1","gaus",0,1);
  f1->SetParameters(1,0.3,p2);
  TF1 *f2 = new TF1("f2","gaus",0,1);
  f2->SetParameters(1,0.7,p2);

/* Set the initial values while t=0*/ 
   for(int i=1;i<1000;i++)
  {
   tmp1 = f1->Eval(i*0.001);
   tmp2 = f2->Eval(i*0.001);   
   Y0[i] = tmp1 + tmp2;
}

  Y0[0] = 0;
  Y0[1000] = 0;

//  cout<< Y0[0] << " "<<3<<endl;

/*Set the values while t=1*/
  for(int i=1;i<1000;i++)
  {
    Y1[i] = r*r*(Y0[i-1] + Y0[i+1]); 
  }
  Y1[0] = 0;
  Y1[1000] = 0;
//cout<<Y1[1000]<<endl;
//  cout << Y0[0] <<" " <<2<< endl;

/*Loop to get the involution*/
for(int m=0;m<130;m++)
{
  for(int i=1;i<1000;i++)
  {
    Y2[i] = r*r*(Y1[i+1]+Y1[i-1])-Y0[i];
  }
  Y2[0] = 0;
  Y2[1000] = 0;
//cout<<Y2[1000]<<endl;

  for(int j=0;j<1001;j++)
  {
    Y0[j] = Y1[j];
    Y1[j] = Y2[j];
  }
//  cout << Y0[1000] << endl;
}

for(int i=0;i<1001;i++)
{
 x[i] = i*0.001;
// cout<<x[i] << " "<< Y2[i]<<endl;

}

   TCanvas *c1 = new TCanvas("wave","wave",800,600);
   TGraph *g1=new TGraph(1001,x,Y0);
   g1->SetTitle("Wave");
   g1->GetXaxis()->SetTitle("x");
   g1->GetYaxis()->SetTitle("y");
  // g1->GetXaxis()->SetLimits(0,2200);
   //g1->GetYaxis()->SetLimits(0,500);
   g1->SetMarkerSize(0.5);
   g1->Draw("APC");




return;
}


