/*******************************
Runs tomsAnalyzer.C with
$INPUT=xxx.inputs
$OUTPUT=xxx.root

Usage: 
root -l -b
.L farmoutAnalyzer.cc
farmoutAnalyzer()

root -l -b -q farmoutAnalyzer.cc
********************************/

#include <TStyle.h>
#include <vector>
#include <TChain.h>
#include "TROOT.h"
#include "TSystem.h"
#include "TApplication.h"
#include <iostream>
#include <exception>

void farmoutAnalyzer()
{
 int error = 0;
 gROOT->ProcessLine(".L tomsAnalyzer.C++", &error);
 if(error!=0){std::cout<<"ERROR LOADING tomsAnalyzer.C"<<std::endl;}
 tomsAnalyzer m;

 // These are the variables coming from HTCondor via FAJ
 TString outfileName = getenv("OUTPUT");
 TString inputListName = getenv("INPUT");
 std::cout << "Output File Name: " << outfileName << std::endl;

 TChain *theChain = new TChain("muEleEventTree/eventTree");

 vector<TString> infileName_dump;
  
 // Find files to be run over and add to TChain
 ifstream inputList;
 inputList.open(inputListName);
 if( !inputList.good() ) {
   std::cerr << 
   "Can not open automatically generated input list file:  "
   << inputListName 
   << std::endl;
   abort();
 }
  
 // Loop through lines in file (paths to .root files)
 // and add to TChain
 TString infileName = "";
 while( !inputList.eof() ) {
  infileName="";
  inputList >> infileName;
  
  std::cout << " Input File Name: "  << infileName <<  std::endl;
 
  theChain->Add( infileName );
 
  infileName_dump.push_back(infileName);
  }
 
  // Initialize and run analyzer on TChain
  m.Init(theChain);
  m.Loop( outfileName );

}
