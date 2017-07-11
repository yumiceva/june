#include "Jet.h"
//#include <TCanvas.h>
//#include "TCollection.h"
//#include "TList.h"

ClassImp(Jet)

#include <string>

/*
Jet::Jet( TLorentzVector &p4, Double_t relIso)
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
Jet::Jet( Jet& rhs)
{
  fp4 = rhs.getP4();
  frelIso = rhs.relIso();
  
}
*/


Jet::~Jet()
{
}
