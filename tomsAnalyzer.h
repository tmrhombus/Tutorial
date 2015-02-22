//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb 19 09:55:57 2015 by ROOT version 5.32/00
// from TTree eventTree/
// found on file: /hdfs/store/user/tperry/Tutorial/TTbar_SemiLeptonic_01.root
//////////////////////////////////////////////////////////

#ifndef tomsAnalyzer_h
#define tomsAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <TH2.h>
#include <iostream>
#include <exception>
#include <cmath>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class tomsAnalyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Histograms to be made
   TH1F h_goodJ1_pt;
   TH1F h_goodMuon_pt;
   TH1F h_goodJ3J4_mass;

   // Bools for Filters
   Bool_t oneGoodMuon;
   Bool_t atLeast4Jets;
   Bool_t atLeast2GoodBJets;
   Bool_t atLeast1GoodBJet;
   Bool_t pass_selections;

   // Declaration of leaf types
   UInt_t          EVENT;
   UInt_t          RUN;
   UInt_t          LUMI;
   vector<double>  *goodEle_charge_vec;
   vector<double>  *goodEle_eta_vec;
   vector<double>  *goodEle_mass_vec;
   vector<double>  *goodEle_phi_vec;
   vector<double>  *goodEle_pt_vec;
   Float_t         goodJ1_CSV;
   Float_t         goodJ1_eta;
   Float_t         goodJ1_mass;
   Float_t         goodJ1_phi;
   Float_t         goodJ1_pt;
   Float_t         goodJ2_CSV;
   Float_t         goodJ2_eta;
   Float_t         goodJ2_mass;
   Float_t         goodJ2_phi;
   Float_t         goodJ2_pt;
   Float_t         goodJ3_CSV;
   Float_t         goodJ3_eta;
   Float_t         goodJ3_mass;
   Float_t         goodJ3_phi;
   Float_t         goodJ3_pt;
   Float_t         goodJ4_CSV;
   Float_t         goodJ4_eta;
   Float_t         goodJ4_mass;
   Float_t         goodJ4_phi;
   Float_t         goodJ4_pt;
   vector<double>  *goodMu_charge_vec;
   vector<double>  *goodMu_eta_vec;
   vector<double>  *goodMu_mass_vec;
   vector<double>  *goodMu_phi_vec;
   vector<double>  *goodMu_pt_vec;
   Float_t         met_eta;
   Float_t         met_pt;
   Float_t         mt_goodElectron;
   Float_t         mt_goodMuon;

   // List of branches
   TBranch        *b_EVENT;   //! 
   TBranch        *b_RUN;   //! 
   TBranch        *b_LUMI;   //! 
   TBranch        *b_goodEle_charge_vec;   //! 
   TBranch        *b_goodEle_eta_vec;   //! 
   TBranch        *b_goodEle_mass_vec;   //! 
   TBranch        *b_goodEle_phi_vec;   //! 
   TBranch        *b_goodEle_pt_vec;   //! 
   TBranch        *b_goodJ1_CSV;   //! 
   TBranch        *b_goodJ1_eta;   //! 
   TBranch        *b_goodJ1_mass;   //! 
   TBranch        *b_goodJ1_phi;   //! 
   TBranch        *b_goodJ1_pt;   //! 
   TBranch        *b_goodJ2_CSV;   //! 
   TBranch        *b_goodJ2_eta;   //! 
   TBranch        *b_goodJ2_mass;   //! 
   TBranch        *b_goodJ2_phi;   //! 
   TBranch        *b_goodJ2_pt;   //! 
   TBranch        *b_goodJ3_CSV;   //! 
   TBranch        *b_goodJ3_eta;   //! 
   TBranch        *b_goodJ3_mass;   //! 
   TBranch        *b_goodJ3_phi;   //! 
   TBranch        *b_goodJ3_pt;   //! 
   TBranch        *b_goodJ4_CSV;   //! 
   TBranch        *b_goodJ4_eta;   //! 
   TBranch        *b_goodJ4_mass;   //! 
   TBranch        *b_goodJ4_phi;   //! 
   TBranch        *b_goodJ4_pt;   //! 
   TBranch        *b_goodMu_charge_vec;   //! 
   TBranch        *b_goodMu_eta_vec;   //! 
   TBranch        *b_goodMu_mass_vec;   //! 
   TBranch        *b_goodMu_phi_vec;   //! 
   TBranch        *b_goodMu_pt_vec;   //! 
   TBranch        *b_met_eta;   //! 
   TBranch        *b_met_pt;   //! 
   TBranch        *b_mt_goodElectron;   //! 
   TBranch        *b_mt_goodMuon;   //! 

   tomsAnalyzer(TTree *tree=0);
   virtual ~tomsAnalyzer();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop( TString outfile_name="outfile" );
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tomsAnalyzer_cxx
tomsAnalyzer::tomsAnalyzer(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/hdfs/store/user/tperry/Tutorial/TTbar/nTuple_TTbar_SemiLeptonic_01.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/hdfs/store/user/tperry/Tutorial/TTbar/nTuple_TTbar_SemiLeptonic_01.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/hdfs/store/user/tperry/Tutorial/TTbar/nTuple_TTbar_SemiLeptonic_01.root:/muEleEventTree");
      dir->GetObject("eventTree",tree);

   }
   Init(tree);
}

tomsAnalyzer::~tomsAnalyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tomsAnalyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tomsAnalyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tomsAnalyzer::Init(TTree *tree)
{

   // Histograms
   h_goodJ1_pt.Clear();
   h_goodJ1_pt = TH1F("h_goodJ1_pt", "Leading Jet pT", 12, 25., 205.);
   h_goodJ1_pt.Sumw2();

   h_goodMuon_pt.Clear();
   h_goodMuon_pt = TH1F("h_goodMuon_pt", "Leading Muon pT", 40, 0., 200.);
   h_goodMuon_pt.Sumw2();

   h_goodJ3J4_mass.Clear();
   h_goodJ3J4_mass = TH1F("h_goodJ3J4_mass", "mass(J3+J4)", 40, 0., 200.);
   h_goodJ3J4_mass.Sumw2();

   // Set object pointer
   goodEle_charge_vec = 0;
   goodEle_eta_vec = 0;
   goodEle_mass_vec = 0;
   goodEle_phi_vec = 0;
   goodEle_pt_vec = 0;
   goodMu_charge_vec = 0;
   goodMu_eta_vec = 0;
   goodMu_mass_vec = 0;
   goodMu_phi_vec = 0;
   goodMu_pt_vec = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EVENT", &EVENT, &b_EVENT);
   fChain->SetBranchAddress("RUN", &RUN, &b_RUN);
   fChain->SetBranchAddress("LUMI", &LUMI, &b_LUMI);
   fChain->SetBranchAddress("goodEle_charge_vec", &goodEle_charge_vec, &b_goodEle_charge_vec);
   fChain->SetBranchAddress("goodEle_eta_vec", &goodEle_eta_vec, &b_goodEle_eta_vec);
   fChain->SetBranchAddress("goodEle_mass_vec", &goodEle_mass_vec, &b_goodEle_mass_vec);
   fChain->SetBranchAddress("goodEle_phi_vec", &goodEle_phi_vec, &b_goodEle_phi_vec);
   fChain->SetBranchAddress("goodEle_pt_vec", &goodEle_pt_vec, &b_goodEle_pt_vec);
   fChain->SetBranchAddress("goodJ1_CSV", &goodJ1_CSV, &b_goodJ1_CSV);
   fChain->SetBranchAddress("goodJ1_eta", &goodJ1_eta, &b_goodJ1_eta);
   fChain->SetBranchAddress("goodJ1_mass", &goodJ1_mass, &b_goodJ1_mass);
   fChain->SetBranchAddress("goodJ1_phi", &goodJ1_phi, &b_goodJ1_phi);
   fChain->SetBranchAddress("goodJ1_pt", &goodJ1_pt, &b_goodJ1_pt);
   fChain->SetBranchAddress("goodJ2_CSV", &goodJ2_CSV, &b_goodJ2_CSV);
   fChain->SetBranchAddress("goodJ2_eta", &goodJ2_eta, &b_goodJ2_eta);
   fChain->SetBranchAddress("goodJ2_mass", &goodJ2_mass, &b_goodJ2_mass);
   fChain->SetBranchAddress("goodJ2_phi", &goodJ2_phi, &b_goodJ2_phi);
   fChain->SetBranchAddress("goodJ2_pt", &goodJ2_pt, &b_goodJ2_pt);
   fChain->SetBranchAddress("goodJ3_CSV", &goodJ3_CSV, &b_goodJ3_CSV);
   fChain->SetBranchAddress("goodJ3_eta", &goodJ3_eta, &b_goodJ3_eta);
   fChain->SetBranchAddress("goodJ3_mass", &goodJ3_mass, &b_goodJ3_mass);
   fChain->SetBranchAddress("goodJ3_phi", &goodJ3_phi, &b_goodJ3_phi);
   fChain->SetBranchAddress("goodJ3_pt", &goodJ3_pt, &b_goodJ3_pt);
   fChain->SetBranchAddress("goodJ4_CSV", &goodJ4_CSV, &b_goodJ4_CSV);
   fChain->SetBranchAddress("goodJ4_eta", &goodJ4_eta, &b_goodJ4_eta);
   fChain->SetBranchAddress("goodJ4_mass", &goodJ4_mass, &b_goodJ4_mass);
   fChain->SetBranchAddress("goodJ4_phi", &goodJ4_phi, &b_goodJ4_phi);
   fChain->SetBranchAddress("goodJ4_pt", &goodJ4_pt, &b_goodJ4_pt);
   fChain->SetBranchAddress("goodMu_charge_vec", &goodMu_charge_vec, &b_goodMu_charge_vec);
   fChain->SetBranchAddress("goodMu_eta_vec", &goodMu_eta_vec, &b_goodMu_eta_vec);
   fChain->SetBranchAddress("goodMu_mass_vec", &goodMu_mass_vec, &b_goodMu_mass_vec);
   fChain->SetBranchAddress("goodMu_phi_vec", &goodMu_phi_vec, &b_goodMu_phi_vec);
   fChain->SetBranchAddress("goodMu_pt_vec", &goodMu_pt_vec, &b_goodMu_pt_vec);
   fChain->SetBranchAddress("met_eta", &met_eta, &b_met_eta);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("mt_goodElectron", &mt_goodElectron, &b_mt_goodElectron);
   fChain->SetBranchAddress("mt_goodMuon", &mt_goodMuon, &b_mt_goodMuon);
   Notify();
}

Bool_t tomsAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tomsAnalyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
#endif // #ifdef tomsAnalyzer_cxx
