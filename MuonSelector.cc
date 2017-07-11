#include "MuonSelector.h"
#include "TLorentzVector.h"
//#include "TCollection.h"
//#include "TList.h"

//ClassImp(MuonSelector)

#include <string>


MuonSelector::MuonSelector( TTree *tree, Long64_t entry, std::string OP)
{
  fReader.SetTree(tree);
  fReader.SetEntry(entry);
  runSelector(OP);
}

MuonSelector::~MuonSelector()
{
}

void MuonSelector::runSelector(std::string OP)
{
  bool IsLoose = false;
  
  for (int i = 0, n =  muPt.GetSize(); i < n; ++i)
    {
      // get pt and eta
      double pt = muPt[i];
      double eta = muEta[i];
      double phi = muPhi[i];

      IsLoose =
        pt > 10.0 &&
        TMath::Abs(eta) < 2.4;

      TLorentzVector p4;
      p4.SetPtEtaPhiE( pt, eta, phi, 0.);
      p4.SetE( p4.P() );

      Muon mu;
      mu.setP4( p4 );
      mu.setrelIso( 0. );
      if (OP == "loose") fmuonList.push_back( mu );
 
    }
}
