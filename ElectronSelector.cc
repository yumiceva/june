#include "ElectronSelector.h"
#include "TLorentzVector.h"
//#include "TCollection.h"
//#include "TList.h"

//ClassImp(ElectronSelector)

#include <string>
#include <algorithm>

ElectronSelector::ElectronSelector( TTree *tree, Long64_t entry, std::string OP)
{
  fReader.SetTree(tree);
  fReader.SetEntry(entry);
  runSelector(OP);
}

ElectronSelector::~ElectronSelector()
{
}

double ElectronSelector::eleEffArea03(double SCEta) {
  double eta = TMath::Abs(SCEta);
  static const double area[7] = {0.130, 0.137, 0.067, 0.089, 0.107, 0.110, 0.138};
  int region = 0;
  if( eta >= 1.0 )   region++;
  if( eta >= 1.479 ) region++;
  if( eta >= 2.0 )   region++;
  if( eta >= 2.2 )   region++;
  if( eta >= 2.3 )   region++;
  if( eta >= 2.4 )   region++;
  return area[region];
}

void ElectronSelector::runSelector(std::string OP)
{
  bool IsVeto = false;
  bool IsLoose = false;
  bool IsTight = false;

  for (int i = 0, n =  elePt.GetSize(); i < n; ++i)
    {
      // get pt and eta
      double pt = elePt[i];
      double eta = eleSCEta[i];
      double phi = elePhi[i];

      double rho_zero = std::max(0.0, (double) *rho );
      double relIsocorr = (elePFChIso[i] +
                           std::max(0.0, elePFNeuIso[i] +
                                    elePFPhoIso[i] -
                                    rho_zero * eleEffArea03(eta) )
                           ) / pt ;



      bool cutbasedID_veto = ( eleIDbit[i] >> 0 & 1)  ;
      bool cutbasedID_loose = ( eleIDbit[i] >> 1 & 1)  ;
      bool cutbasedID_tight = ( eleIDbit[i] >> 3 & 1)  ;

      //bool mvabasedID = eleIDMVATrg[i] > 0;


      IsVeto =
        pt > 15.0 &&
        fabs(eta) < 2.5 &&
        cutbasedID_veto;

      IsLoose =
        pt > 15.0 &&
        fabs(eta) < 2.5 &&
        cutbasedID_loose;

      IsTight =
        pt > 30 &&
        fabs(eta) < 2.4 &&
        cutbasedID_tight;

      TLorentzVector p4;
      p4.SetPtEtaPhiE( pt, eta, phi, 0.);
      p4.SetE( p4.P() );

      Electron ele;
      ele.setP4( p4 );
      ele.setrelIso( relIsocorr );

      if ( OP == "veto" && IsVeto ) fList.push_back( ele );
      if ( OP == "loose" && IsLoose ) fList.push_back( ele );
      if ( OP == "tight" && IsTight ) fList.push_back( ele );

    }
}
