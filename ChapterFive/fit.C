#include <fstream>
#include <cstdlib>
#include <iostream>
#include "TString.h"
#include "TMath.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TAxis.h"
#include "TStyle.h"

using namespace std;

int main(int argc, char* argv[]) {
    TString filename(argv[1]);
    ifstream infile;
    infile.open(filename);
    if (!infile.good()) {
        cout << "Cannot open this file: " << filename << endl;
        return -1;
    }

    const int Num = 5;
    double EmptyNoise[Num];
    double EmptySignal[Num];
    double AttenNoise[Num];
    double AttenSignal[Num];
    int i=0;
    int NumEmpNoi = 0;
    int NumEmpSig = 0;
    int NumAttNoi = 0;
    int NumAttSig = 0;
    double column1;
    double column2;
    double column3;
    double column4;
    double column5;
    while (!infile.eof()) {
        i++;
        infile >> column1 >> column2 >> column3 >> column4 >> column5;
        if (!infile.eof()) {
            if (i%5==1) {
                EmptyNoise[NumEmpNoi] = (column1 + column2 + column3 + column4 + column5)/5.0;
                NumEmpNoi++;
            }
            if (i%5==2) {
                EmptySignal[NumEmpSig] = (column1 + column2 + column3 + column4 + column5)/5.0;
                NumEmpSig++;
            }
            if (i%5==3) {
                AttenNoise[NumAttNoi] = (column1 + column2 + column3 + column4 + column5)/5.0;
                NumAttNoi++;
            }
            if (i%5==4) {
                AttenSignal[NumAttSig] = (column1 + column2 + column3 + column4 + column5)/5.0;
                NumAttSig++;
            }
        }
    }
    infile.close();

    ifstream infile2;
    infile2.open(filename);
    double StdEmptyNoise[Num];
    double StdEmptySignal[Num];
    double StdAttenNoise[Num];
    double StdAttenSignal[Num];
    int k=0;
    int NumStdEmpNoi = 0;
    int NumStdEmpSig = 0;
    int NumStdAttNoi = 0;
    int NumStdAttSig = 0;
    while (!infile2.eof()) {
        k++;
        infile2 >> column1 >> column2 >> column3 >> column4 >> column5;
        if (!infile2.eof()) {
            if (k%5==1) {
                StdEmptyNoise[NumStdEmpNoi] = (pow((column1 - EmptyNoise[NumStdEmpNoi]),2) + 
                                               pow((column2 - EmptyNoise[NumStdEmpNoi]),2) + 
                                               pow((column3 - EmptyNoise[NumStdEmpNoi]),2) + 
                                               pow((column4 - EmptyNoise[NumStdEmpNoi]),2) + 
                                               pow((column5 - EmptyNoise[NumStdEmpNoi]),2))/(Num-1);  
                NumStdEmpNoi++;
            }
            if (k%5==2) {
                StdEmptySignal[NumStdEmpSig] = (pow((column1 - EmptySignal[NumStdEmpSig]),2) + 
                                                pow((column2 - EmptySignal[NumStdEmpSig]),2) + 
                                                pow((column3 - EmptySignal[NumStdEmpSig]),2) + 
                                                pow((column4 - EmptySignal[NumStdEmpSig]),2) + 
                                                pow((column5 - EmptySignal[NumStdEmpSig]),2))/(Num-1);  
                NumStdEmpSig++;
            }
            if (k%5==3) {
                StdAttenNoise[NumStdAttNoi] = (pow((column1 - AttenNoise[NumStdAttNoi]),2) + 
                                               pow((column2 - AttenNoise[NumStdAttNoi]),2) + 
                                               pow((column3 - AttenNoise[NumStdAttNoi]),2) + 
                                               pow((column4 - AttenNoise[NumStdAttNoi]),2) + 
                                               pow((column5 - AttenNoise[NumStdAttNoi]),2))/(Num-1);  
                NumStdAttNoi++;
            }
            if (k%5==4) {
                StdAttenSignal[NumStdAttSig] = (pow((column1 - AttenSignal[NumStdAttSig]),2) + 
                                                pow((column2 - AttenSignal[NumStdAttSig]),2) + 
                                                pow((column3 - AttenSignal[NumStdAttSig]),2) + 
                                                pow((column4 - AttenSignal[NumStdAttSig]),2) + 
                                                pow((column5 - AttenSignal[NumStdAttSig]),2))/(Num-1);  
                NumStdAttSig++;
            }
        }
    }
    infile2.close();
    

    double InPower[Num];
    double OutPower[Num];
    double InError[Num];
    double OutError[Num];
    for (int j=0;j<Num;j++) {
        InPower[j] = EmptySignal[j] - EmptyNoise[j];
        InError[j] = TMath::Sqrt(StdEmptySignal[j] + StdEmptyNoise[j]);
        OutPower[j] = AttenSignal[j] - AttenNoise[j];
        OutError[j] = TMath::Sqrt(StdAttenSignal[j] + StdAttenNoise[j]);
    }


    TCanvas* cc = new TCanvas("AbsoluteMeasurement","RayleighScattering",800,600);

    //gStyle->SetOptFit(kTRUE);
    gPad->SetLeftMargin(0.125);
    gStyle->SetOptFit(1111111);
    gStyle->SetStatY(0.85);
    gStyle->SetStatX(0.55);
    gStyle->SetStatW(0.18);
    gStyle->SetStatH(0.15);
//    gStyle->SetPadLeftMargin(0.2);

    TF1* fun = new TF1("fun","[0] * x + [1]", 0.0, 100000);
    // fun->FixParameter(1, 0.0);
    //
    TGraphErrors* tg = new TGraphErrors(Num, OutPower, InPower, OutError, InError);
    tg->Fit(fun,"EM0");
	tg->GetXaxis()->SetTitle("Number of Scattering Photons");
	tg->GetYaxis()->SetTitle("Number of Incident Photons");
    tg->GetYaxis()->SetTitleOffset(1.5);
	tg->SetTitle("");
	//tg->GetXaxis()->SetRangeUser(0.0,1500000.0);
	//tg->GetYaxis()->SetRangeUser(0.0,25000);
    tg->Draw("AP");
	fun->SetLineColor(kBlack);
	fun->SetLineStyle(1);
	fun->SetLineWidth(1);
	//fun->GetParameters();
    fun->Draw("same");

    TString output = filename.Remove(filename.Length()-4);
    cc->SaveAs(output+".png");

    return 0;
}
