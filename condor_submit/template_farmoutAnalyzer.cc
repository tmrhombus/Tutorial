/********************************
Instantiates tomsAnalyzer.C with
the correct chain and naming
for a definable set of parameters

Usage: 
root -l -b
.L SAMPLE_callAnalyzer.cc
SAMPLE_callAnalyzer()

root -l -b -q SAMPLE_callAnalyzer.cc
********************************/

#include <TStyle.h>
#include <vector>
#include <TChain.h>
#include "TROOT.h"
#include "TSystem.h"
#include "TApplication.h"
#include <iostream>
#include <exception>

void SAMPLE_callAnalyzer()
{
 int error = 0;
 gROOT->ProcessLine(".L tomsAnalyzer.C++", &error);
 if(error!=0){std::cout<<"ERROR LOADING tomsAnalyzer.C"<<std::endl;}
 tomsAnalyzer m;

 TChain *theChain = new TChain("muEleEventTree/eventTree");
 theChain->Add("THEFILE");

 TTree* tree;
 TString dirName;
 
 m.Init(theChain); 
    
 TString name = "SAMPLE_FILENAME";
 std::cout<<name<<"\n";

 m.Loop( name );

}
