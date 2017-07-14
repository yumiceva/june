#ifndef JetSelector_H
#define JetSelector_H

#include "TNamed.h"
#include "TLorentzVector.h"
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include "Jet.h"
#include <string>
#include <vector>

//class TCollection;

class JetSelector
{
public:
  JetSelector() { }
  JetSelector( TTree *tree, Long64_t entry, std::string OP, std::string btagger = "");
  //JetSelector(const char *name);
  //JetSelector( JetSelector& rhs);
  ~JetSelector();
  //void Draw(Option_t * = 0);
  //void Fill(bool selected, double var);
  //void Merge(TCollection *list);
  //Double_t relIso() { return frelIso; }
  //TLorentzVector getP4() { return fp4; }
  const std::vector< Jet > &getList() const { return fList; }
  void runSelector( std::string OP );

  //ClassDef(JetSelector,1);
private:
  //TLorentzVector fp4;
  std::string fbtagger;
  std::vector< Jet > fList;

  TTreeReader     fReader;  //!the tree reader

  TTreeReaderValue<Int_t> nJet = {fReader, "nJet"};
  TTreeReaderArray<float> jetPt = {fReader, "jetPt"};
  TTreeReaderArray<float> jetEn = {fReader, "jetEn"};
  TTreeReaderArray<float> jetEta = {fReader, "jetEta"};
  TTreeReaderArray<float> jetPhi = {fReader, "jetPhi"};
  TTreeReaderArray<float> jetRawPt = {fReader, "jetRawPt"};
  TTreeReaderArray<float> jetRawEn = {fReader, "jetRawEn"};
  TTreeReaderArray<float> jetMt = {fReader, "jetMt"};
  TTreeReaderArray<float> jetArea = {fReader, "jetArea"};
  TTreeReaderArray<float> jetLeadTrackPt = {fReader, "jetLeadTrackPt"};
  TTreeReaderArray<float> jetLeadTrackEta = {fReader, "jetLeadTrackEta"};
  TTreeReaderArray<float> jetLeadTrackPhi = {fReader, "jetLeadTrackPhi"};
  TTreeReaderArray<int> jetLepTrackPID = {fReader, "jetLepTrackPID"};
  TTreeReaderArray<float> jetLepTrackPt = {fReader, "jetLepTrackPt"};
  TTreeReaderArray<float> jetLepTrackEta = {fReader, "jetLepTrackEta"};
  TTreeReaderArray<float> jetLepTrackPhi = {fReader, "jetLepTrackPhi"};
  TTreeReaderArray<float> jetCSV2BJetTags = {fReader, "jetCSV2BJetTags"};
  TTreeReaderArray<float> jetJetProbabilityBJetTags = {fReader, "jetJetProbabilityBJetTags"};
  TTreeReaderArray<float> jetpfCombinedMVAV2BJetTags = {fReader, "jetpfCombinedMVAV2BJetTags"};
  TTreeReaderArray<int> jetPartonID = {fReader, "jetPartonID"};
  TTreeReaderArray<int> jetHadFlvr = {fReader, "jetHadFlvr"};
  TTreeReaderArray<float> jetGenJetEn = {fReader, "jetGenJetEn"};
  TTreeReaderArray<float> jetGenJetPt = {fReader, "jetGenJetPt"};
  TTreeReaderArray<float> jetGenJetEta = {fReader, "jetGenJetEta"};
  TTreeReaderArray<float> jetGenJetPhi = {fReader, "jetGenJetPhi"};
  TTreeReaderArray<int> jetGenPartonID = {fReader, "jetGenPartonID"};
  TTreeReaderArray<float> jetGenEn = {fReader, "jetGenEn"};
  TTreeReaderArray<float> jetGenPt = {fReader, "jetGenPt"};
  TTreeReaderArray<float> jetGenEta = {fReader, "jetGenEta"};
  TTreeReaderArray<float> jetGenPhi = {fReader, "jetGenPhi"};
  TTreeReaderArray<int> jetGenPartonMomID = {fReader, "jetGenPartonMomID"};
  TTreeReaderArray<float> jetP4Smear = {fReader, "jetP4Smear"};
  TTreeReaderArray<float> jetP4SmearUp = {fReader, "jetP4SmearUp"};
  TTreeReaderArray<float> jetP4SmearDo = {fReader, "jetP4SmearDo"};
  TTreeReaderValue<vector<bool>> jetPFLooseId = {fReader, "jetPFLooseId"};
  TTreeReaderArray<int> jetID = {fReader, "jetID"};
  TTreeReaderArray<float> jetPUID = {fReader, "jetPUID"};
  TTreeReaderArray<int> jetPUFullID = {fReader, "jetPUFullID"};
  TTreeReaderArray<float> jetJECUnc = {fReader, "jetJECUnc"};
  TTreeReaderArray<unsigned int> jetFiredTrgs = {fReader, "jetFiredTrgs"};
  TTreeReaderArray<float> jetCHF = {fReader, "jetCHF"};
  TTreeReaderArray<float> jetNHF = {fReader, "jetNHF"};
  TTreeReaderArray<float> jetCEF = {fReader, "jetCEF"};
  TTreeReaderArray<float> jetNEF = {fReader, "jetNEF"};
  TTreeReaderArray<int> jetNCH = {fReader, "jetNCH"};
  TTreeReaderArray<int> jetNNP = {fReader, "jetNNP"};
};

#endif
