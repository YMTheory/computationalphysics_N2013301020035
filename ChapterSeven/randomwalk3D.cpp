#include<stdio.h>
#include"iostream.h"
#include"TGraph.h"
#include"TPaveText.h"
#include"TMath.h"
#include<iomanip>
#include"TRandom.h"

double radius[100];
double theta[100];
double phi[100];
double step[100];
double distance[100];
double tmp1[100];
double tmp2[100];
double x[100];
double y[100];
double z[100];
double X=0;
double Y=0;
double Z=0;
void randomgenerator()
{
TRandom3 r;
r.RndmArray(100,radius);
r.RndmArray(100,tmp1);
r.RndmArray(100,tmp2);
for(int j=0;j<100;j++)
{
    theta[j] = tmp1[j]*2*3.14;
    phi[j] = tmp2[j]*3.14;
}

return;
}

void randomwalk3D()
{

randomgenerator();
for(int i=0;i<100;i++)
{cout<<radius[i]<<" "<<phi[i]<<endl;
step[i] = i;
x[i] = radius[i]*sin(phi[i])*cos(theta[i]);
y[i] = radius[i]*sin(phi[i])*sin(theta[i]);
z[i] = radius[i]*cos(phi[i]);
}
for(int i=0;i<100;i++)
{
X += x[i];
Y += y[i];
Z += z[i];
distance[i] = X*X+Y*Y+Z*Z;
cout<<distance[i]<<endl;
}

TCanvas *c1 = new TCanvas("randomwalk","randomwalk",1200,1000);
TGraph *g1 = new TGraph(100,step,distance);
g1->SetTitle("RandomWalk3D");
g1->GetXaxis()->SetTitle("step");
g1->GetYaxis()->SetTitle("distance");
g1->SetLineWidth(3);
g1->SetLineColor(2);
g1->Draw("APL");

return;
}
