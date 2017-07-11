#ifndef MuonSelector_H
#define MuonSelector_H

#include "TNamed.h"
#include "TLorentzVector.h"
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include "Muon.h"
#include <string>
#include <vector>

//class TCollection;

class MuonSelector
{
public:
  MuonSelector() { }
  MuonSelector( TTree *tree, Long64_t entry, std::string OP);
  //MuonSelector(const char *name);
  //MuonSelector( MuonSelector& rhs);
  ~MuonSelector();
  //void Draw(Option_t * = 0);
  //void Fill(bool selected, double var);
  //void Merge(TCollection *list);
  //Double_t relIso() { return frelIso; }
  //TLorentzVector getP4() { return fp4; }
  const std::vector< Muon > &getList() const { return fmuonList; }
  void runSelector( std::string OP );

  //ClassDef(MuonSelector,1);
private:
  //TLorentzVector fp4;
  //Double_t frelIso;
  std::vector< Muon > fmuonList;

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

};

#endif
