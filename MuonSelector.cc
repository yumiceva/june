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
  bool IsTight = false;

  for (int i = 0, n =  muPt.GetSize(); i < n; ++i)
    {
      // get pt and eta
      double pt = muPt[i];
      double eta = muEta[i];
      double phi = muPhi[i];

      // check muon type
      static const unsigned int GlobalMuon     =  1<<1;
      static const unsigned int TrackerMuon    =  1<<2;
      static const unsigned int PFMuon =  1<<5;
      bool isGlobalMuon  = muType[i] & GlobalMuon;
      bool isTrackerMuon = muType[i] & TrackerMuon;
      bool isPFMuon      = muType[i] & PFMuon;

      double relIsocorr = ( muPFChIso[i] + fmax(0.0, muPFNeuIso[i] + muPFPhoIso[i] -0.5*muPFPUIso[i] ) ) / pt;

      IsLoose =
        pt > 15.0 &&
        fabs(eta) < 2.4 &&
        relIsocorr < 0.25 &&
        isPFMuon && ( isGlobalMuon || isTrackerMuon);

      IsTight =
        pt > 30 &&
        fabs(eta) < 2.4 &&
        relIsocorr < 0.15 &&
        muChi2NDF[i] < 10 &&
        muTrkLayers[i] > 5 &&
        muMuonHits[i] > 0 &&
                          muD0[i] < 0.2 &&
                          fabs( muDz[i] ) < 0.5 && //check this
                          muPixelHits[i] > 0 &&
                          muStations[i] > 1 &&
                          isPFMuon && isGlobalMuon && isTrackerMuon;

      TLorentzVector p4;
      p4.SetPtEtaPhiE( pt, eta, phi, 0.);
      p4.SetE( p4.P() );

      Muon mu;
      mu.setP4( p4 );
      mu.setrelIso( 0. );
      if ( OP == "loose" && IsLoose ) fmuonList.push_back( mu );
      if ( OP == "tight" && IsTight ) fmuonList.push_back( mu );

    }
}
