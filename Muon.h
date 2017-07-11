#ifndef Muon_H
#define Muon_H

#include "TObject.h"
#include "TLorentzVector.h"
//#include <TTreeReader.h>
//#include <TTreeReaderValue.h>
//#include <TTreeReaderArray.h>


//class TCollection;

class Muon : public TObject
{
public:
  Muon();// : frelIso(0) { }
  //Muon( TLorentzVector &p4, Double_t relIso );
  //Muon( TTree *tree, Long64_t entry, int n );
  //Muon(const char *name);
  //Muon( Muon& rhs);
  ~Muon();
  //void Draw(Option_t * = 0);
  //void Fill(bool selected, double var);
  //void Merge(TCollection *list);
  void setP4( TLorentzVector &p4 ) { fp4 = p4; }
  void setrelIso( Double_t relIso ) { frelIso = relIso; }
  Double_t relIso() { return frelIso; }
  TLorentzVector getP4() { return fp4; }

  ClassDef(Muon,1);

private:
  TLorentzVector fp4;
  Double_t frelIso;
  /*
  TTreeReader     fReader;  //!the tree reader
  TTreeReaderValue<Int_t> nMu = {fReader, "nMu"};
  TTreeReaderArray<float> muPt = {fReader, "muPt"};
  TTreeReaderArray<float> muEta = {fReader, "muEta"};
  TTreeReaderArray<float> muPhi = {fReader, "muPhi"};
  TTreeReaderArray<int> muType = {fReader, "muType"};
  TTreeReaderArray<float> muD0 = {fReader, "muD0"};
  TTreeReaderArray<float> muDz = {fReader, "muDz"};
  TTreeReaderArray<float> muChi2NDF = {fReader, "muChi2NDF"};
  TTreeReaderArray<int> muTrkLayers = {fReader, "muTrkLayers"};
  TTreeReaderArray<int> muPixelHits = {fReader, "muPixelHits"};
  TTreeReaderArray<int> muMuonHits = {fReader, "muMuonHits"};
  TTreeReaderArray<int> muStations = {fReader, "muStations"};
  TTreeReaderArray<float> muPFChIso = {fReader, "muPFChIso"};
  TTreeReaderArray<float> muPFPhoIso = {fReader, "muPFPhoIso"};
  TTreeReaderArray<float> muPFNeuIso = {fReader, "muPFNeuIso"};
  TTreeReaderArray<float> muPFPUIso = {fReader, "muPFPUIso"};
  */

};

#endif
