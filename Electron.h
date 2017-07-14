#ifndef Electron_H
#define Electron_H

#include "TObject.h"
#include "TLorentzVector.h"
//#include <TTreeReader.h>
//#include <TTreeReaderValue.h>
//#include <TTreeReaderArray.h>


//class TCollection;

class Electron : public TObject
{
public:
  Electron();// : frelIso(0) { }
  ~Electron();

  void setP4( TLorentzVector &p4 ) { fp4 = p4; }
  void setrelIso( Double_t relIso ) { frelIso = relIso; }
  Double_t relIso() { return frelIso; }
  TLorentzVector getP4() { return fp4; }

  ClassDef(Electron,1);

private:
  TLorentzVector fp4;
  Double_t frelIso;

};

#endif
