#ifndef Jet_H
#define Jet_H

#include "TObject.h"
#include "TLorentzVector.h"


//class TCollection;

class Jet : public TObject
{
public:
  Jet();// : frelIso(0) { }
  //Jet( TLorentzVector &p4, Double_t relIso );
  //Jet( TTree *tree, Long64_t entry, int n );
  //Jet(const char *name);
  //Jet( Jet& rhs);
  ~Jet();
  //void Draw(Option_t * = 0);
  //void Fill(bool selected, double var);
  //void Merge(TCollection *list);
  void setP4( TLorentzVector &p4 ) { fp4 = p4; }
  //void setrelIso( Double_t relIso ) { frelIso = relIso; }
  //Double_t relIso() { return frelIso; }
  TLorentzVector getP4() { return fp4; }

  ClassDef(Jet,1);

private:
  TLorentzVector fp4;


};

#endif
