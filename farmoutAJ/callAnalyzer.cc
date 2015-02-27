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

void callAnalyzer()
{
 int error = 0;
 gROOT->ProcessLine(".L tomsAnalyzer.C++", &error);
 if(error!=0){std::cout<<"ERROR LOADING tomsAnalyzer.C"<<std::endl;}
 tomsAnalyzer m;

 TString outfileName = getenv("OUTPUT");
 TString inputListName = getenv("INPUT");

 TChain *theChain = new TChain("muEleEventTree/eventTree");

 vector<TString> infileName_dump;
  
 ifstream inputList;
 //inputList.open(inputListName.c_str());
 inputList.open(inputListName);
 if( !inputList.good() ) {
   std::cerr << "Cannot open the file: \"" << inputListName+"\"!"<<std::endl;
   abort();
 }
  
 // OK we have the file!
 TString infileName = "";
 while( !inputList.eof() ) {
  infileName="";
  inputList >> infileName;
  
  // Do your stuff here! maybe:
  if (infileName=="") continue;
  if (infileName== "#") continue;

  std::cout << "Output File Name: " << outfileName << std::endl;
  std::cout << "Input File Name: "  << infileName <<  std::endl;
 
  theChain->Add( infileName );
 
  // TTree* tree;
  // TString dirName;
  
  m.Init(theChain); 
     
  m.Loop( outfileName );

  infileName_dump.push_back(infileName);
  }
 

}
