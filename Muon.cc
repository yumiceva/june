#include "Muon.h"
//#include <TCanvas.h>
//#include "TCollection.h"
//#include "TList.h"

ClassImp(Muon)

#include <string>

/*
Muon::Muon( TLorentzVector &p4, Double_t relIso)
{
  //fReader.SetTree(tree);
  //fReader.SetEntry(entry);

  //fp4.SetPtEtaPhiE( muPt[n], muEta[n], muPhi[n], 0.);
  //fp4.SetE( fp4.P() );
  //frelIso = ( muPFChIso[n] + fmax(0.0, muPFNeuIso[n] + muPFPhoIso[n] -0.5*muPFPUIso[n] ) ) / muPt[n];
  fp4 = p4;
  frelIso = relIso;
}
*/
/*
Muon::Muon( Muon& rhs)
{
  fp4 = rhs.getP4();
  frelIso = rhs.relIso();
  
}
*/

Muon::Muon(): frelIso(0)
{

}

Muon::~Muon()
{
}
