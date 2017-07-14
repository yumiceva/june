#include "JetSelector.h"
#include "TLorentzVector.h"
//#include "TCollection.h"
//#include "TList.h"

//ClassImp(JetSelector)

#include <string>


JetSelector::JetSelector( TTree *tree, Long64_t entry, std::string OP, std::string btagger )
{
  fReader.SetTree(tree);
  fReader.SetEntry(entry);
  runSelector(OP);
  fbtagger = btagger;
}

JetSelector::~JetSelector()
{
}

void JetSelector::runSelector(std::string OP)
{
  bool IsLoose = false;
  bool IsTight = false;

  for (int i = 0, n =  jetPt.GetSize(); i < n; ++i)
    {
      // get pt and eta
      double pt = jetPt[i];
      double eta = jetEta[i];
      double phi = jetPhi[i];
      double en = jetEn[i];
      
      float cut_btag = -100;
      if ( fbtagger == "CSVv2L" ) cut_btag = 0.5426;
      if ( fbtagger == "CSVv2M" ) cut_btag = 0.8484;
      if ( fbtagger == "CSVv2T" ) cut_btag = 0.9535;

      bool Isbtagged = false;
      if ( fbtagger.find("CSVv2") != std::string::npos && jetCSV2BJetTags[i] > cut_btag ) Isbtagged = true;

      IsLoose =
        pt > 30.0 &&
        fabs(eta) < 2.4 &&
        jetID[i] >>1 & 1;

      IsTight =
        pt > 30 &&
        fabs(eta) < 2.4 &&
        jetID[i] >>2 & 1;

      TLorentzVector p4;
      p4.SetPtEtaPhiE( pt, eta, phi, en);
      p4.SetE( p4.P() );

      Jet jet;
      jet.setP4( p4 );
      jet.setIsbtag( Isbtagged );
      if ( OP == "loose" && IsLoose ) fList.push_back( jet );
      if ( OP == "tight" && IsTight ) fList.push_back( jet );

    }
}
