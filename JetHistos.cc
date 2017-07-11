//////////////////////////////////////////////////////////
//
//
// Francisco Yumiceva
// Florida Institute of Technology
/////////////////////////////////////////////////////////

#include "JetHistos.h"
#include "TLorentzVector.h"
#include "TCollection.h"
#include "TList.h"

#include<iostream>
using namespace std;

ClassImp(JetHistos)

JetHistos::JetHistos(const char *name)
{
  SetName(name);
  fprefix = string(name)+"_";

  fhtmp = new TH1F(name,name,100,0,500);

  Book(fprefix+"Pt",fprefix+"Pt",30,0,300,"Jet p_{T} [GeV]","Events / 10 GeV");
  Book(fprefix+"Eta",fprefix+"Eta",26,-2.6,2.6,"Jet #eta","Events / 0.2");
  Book(fprefix+"Phi",fprefix+"Phi",20,-3.15,3.15,"Jet #phi","Events /");
  
}

JetHistos::JetHistos( JetHistos& rhs )
  : TNamed()
{
  fhists = rhs.GetMap();
}

JetHistos::~JetHistos()
{
  delete fhtmp;
  fhists.clear();
}

void JetHistos::Fill( Jet p)
{
  TLorentzVector p4 = p.getP4();

  fhists[fprefix+"Pt"]->Fill( p4.Pt() );
  //fhists[fprefix+"Eta"]->Fill( ftree->muEta->at(imu) );
  //fhists[fprefix+"Phi"]->Fill( ftree->muPhi->at(imu) );

}

Long64_t JetHistos::Merge(TCollection *list)
{
  Long64_t rc = 0;
  if (!list) return rc;
  if (list->IsEmpty()) return rc;

  TIter nxtm(list);
  JetHistos *m = 0;
  // (Assume objects in the collection are Tmap; a check could be added ...)
  while ( (m = (JetHistos *) nxtm())) {

    std::map< std::string, TH1F* > mymap;
    mymap = m->GetMap();

    for ( std::map< std::string, TH1F*>::iterator it= mymap.begin(); it != mymap.end(); ++it)
      {
        fhists[ it->first ]->Add( it->second );
      }
  }
  return rc;
}

/*
Long64_t JetHistos::Merge(TCollection *li)
{
  Long64_t rc = 0;

  // If empty list, nothing to do
  if (!li || li->GetSize() < 1) return rc;

  // Loop over the objects in the collection
  TIter nxtm(li);
  JetHistos *m = 0;
  // (Assume objects in the collection are Tmap; a check could be added ...)
  while ( (m = (JetHistos *) nxtm())) {

    std::map< std::string, TH1F* > mymap;
    mymap = m->GetMap();
    
    for ( std::map< std::string, TH1F*>::iterator it= mymap.begin(); it != mymap.end(); ++it)
      {
        fhists[ it->first ]->Add( it->second );
      }
  }
  return rc;

}
*/
