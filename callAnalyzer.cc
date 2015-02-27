// For running local tests,
// this is the same as template_callAnalyzer
// but with the fields filled in 
//
// root -l -b -q callAnalyzer.cc

#include <TStyle.h>
#include <vector>
#include <TChain.h>
#include "TROOT.h"
#include "TSystem.h"
#include "TApplication.h"
#include <iostream>
#include <exception>

void callAnalyzer()
{
 int error = 0;
 gROOT->ProcessLine(".L tomsAnalyzer.C++", &error);
 if(error!=0){std::cout<<"ERROR LOADING tomsAnalyzer.C"<<std::endl;}
 tomsAnalyzer m;

 TChain *theChain = new TChain("muEleEventTree/eventTree");
 theChain->Add("/hdfs/store/user/tperry/Tutorial/TTbar/nTuple_TTbar_SemiLeptonic_01.root");

 TTree* tree;
 TString dirName;
 
 m.Init(theChain); 
    
 TString name = "TTbar_nTuple_TTbar_SemiLeptonic_01.root";
 std::cout<<name<<"\n";

 m.Loop( name );

}

