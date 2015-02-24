#define tomsAnalyzer_cxx
#include "tomsAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void tomsAnalyzer::Loop( TString outfile_name )
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb; 
      if(!nb){std::cout<<"tomsAnalyzer.C can't fChain->GetEntry(jentry)\n";}

      // the goodMuon collection already has ID,Isolation taken care of
      // but let's require that there's exactly one muon and it has pT > 30
      oneGoodMuon = kFALSE;
      if( goodMu_pt_vec->size()==1 ){
       oneGoodMuon =  goodMu_pt_vec->at(0) > 30;
      }
 
      // let's make a composite variable: dijet mass of J3J4
      goodJ3J4_mass = -1.;
      // at least 4 jets
      atLeast4Jets = kFALSE;
      if( goodJ1_pt > 30 && goodJ2_pt > 30 && goodJ3_pt > 30 && goodJ4_pt > 30){
       atLeast4Jets = kTRUE;
       
       // make the dijet mass
       fourVec_J3.SetPtEtaPhiM(goodJ3_pt, goodJ3_eta, goodJ3_phi, goodJ3_mass);
       fourVec_J4.SetPtEtaPhiM(goodJ4_pt, goodJ4_eta, goodJ4_phi, goodJ4_mass);
       fourVec_J3J4 = fourVec_J3 + fourVec_J4;
       goodJ3J4_mass = fourVec_J3J4.M();
       
      }

      // at least 1 bTagged jets
      atLeast1GoodBJet = kFALSE;
      if( goodJ1_CSV > 0.898 ){
       atLeast1GoodBJet = kTRUE;
      }

      // at least 2 bTagged jets
      atLeast2GoodBJets = kFALSE;
      if( goodJ1_CSV > 0.898 && goodJ2_CSV > 0.898 ){
       atLeast2GoodBJets = kTRUE;
      }

      // Does event pass our selection
      pass_selections = kFALSE;
      //if( oneGoodMuon && atLeast4Jets && atLeast2GoodBJets ){
      if( oneGoodMuon && atLeast4Jets && atLeast1GoodBJet ){
       pass_selections = kTRUE;
      }

      // if event passes selection, fill histogram
      if( pass_selections ){
       h_goodJ1_pt.Fill( goodJ1_pt );
       h_goodMuon_pt.Fill( goodMu_pt_vec->at(0) );
       h_goodJ3J4_mass.Fill( goodJ3J4_mass );
      }
   } // loop over all events

   // write the histograms to file
   TFile *outfile = new TFile(outfile_name+".root","RECREATE");
   outfile->cd();

   h_goodJ1_pt.Write();
   h_goodMuon_pt.Write();
   h_goodJ3J4_mass.Write();

//   h_goodJ1_pt.Delete();
//   h_goodMuon_pt.Delete();
//   h_goodJ3J4_mass.Delete();

   outfile->Close();

}
