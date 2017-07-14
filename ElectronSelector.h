#ifndef ElectronSelector_H
#define ElectronSelector_H

#include "TNamed.h"
#include "TLorentzVector.h"
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include "Electron.h"
#include <string>
#include <vector>

//class TCollection;

class ElectronSelector
{
public:
  ElectronSelector() { }
  ElectronSelector( TTree *tree, Long64_t entry, std::string OP);
  //ElectronSelector(const char *name);
  //ElectronSelector( ElectronSelector& rhs);
  ~ElectronSelector();
  //void Draw(Option_t * = 0);
  //void Fill(bool selected, double var);
  //void Merge(TCollection *list);
  //Double_t relIso() { return frelIso; }
  //TLorentzVector getP4() { return fp4; }
  const std::vector< Electron > &getList() const { return fList; }
  void runSelector( std::string OP );
  double eleEffArea03(double SCEta);

  //ClassDef(ElectronSelector,1);
private:
  //TLorentzVector fp4;
  //Double_t frelIso;
  std::vector< Electron > fList;

  TTreeReader     fReader;  //!the tree reader

  TTreeReaderValue<Float_t> rho = {fReader, "rho"};
  TTreeReaderValue<Float_t> rhoCentral = {fReader, "rhoCentral"};
  TTreeReaderValue<Int_t> nEle = {fReader, "nEle"};
  TTreeReaderArray<int> eleCharge = {fReader, "eleCharge"};
  TTreeReaderArray<int> eleChargeConsistent = {fReader, "eleChargeConsistent"};
  TTreeReaderArray<float> eleEn = {fReader, "eleEn"};
  TTreeReaderArray<float> eleSCEn = {fReader, "eleSCEn"};
  TTreeReaderArray<float> eleESEn = {fReader, "eleESEn"};
  TTreeReaderArray<float> eleESEnP1 = {fReader, "eleESEnP1"};
  TTreeReaderArray<float> eleESEnP2 = {fReader, "eleESEnP2"};
  TTreeReaderArray<float> eleD0 = {fReader, "eleD0"};
  TTreeReaderArray<float> eleDz = {fReader, "eleDz"};
  TTreeReaderArray<float> eleSIP = {fReader, "eleSIP"};
  TTreeReaderArray<float> elePt = {fReader, "elePt"};
  TTreeReaderArray<float> eleEta = {fReader, "eleEta"};
  TTreeReaderArray<float> elePhi = {fReader, "elePhi"};
  TTreeReaderArray<float> eleR9 = {fReader, "eleR9"};
  TTreeReaderArray<float> eleCalibPt = {fReader, "eleCalibPt"};
  TTreeReaderArray<float> eleCalibEn = {fReader, "eleCalibEn"};
  TTreeReaderArray<float> eleSCEta = {fReader, "eleSCEta"};
  TTreeReaderArray<float> eleSCPhi = {fReader, "eleSCPhi"};
  TTreeReaderArray<float> eleSCRawEn = {fReader, "eleSCRawEn"};
  TTreeReaderArray<float> eleSCEtaWidth = {fReader, "eleSCEtaWidth"};
  TTreeReaderArray<float> eleSCPhiWidth = {fReader, "eleSCPhiWidth"};
  TTreeReaderArray<float> eleHoverE = {fReader, "eleHoverE"};
  TTreeReaderArray<float> eleEoverP = {fReader, "eleEoverP"};
  TTreeReaderArray<float> eleEoverPout = {fReader, "eleEoverPout"};
  TTreeReaderArray<float> eleEoverPInv = {fReader, "eleEoverPInv"};
  TTreeReaderArray<float> eleBrem = {fReader, "eleBrem"};
  TTreeReaderArray<float> eledEtaAtVtx = {fReader, "eledEtaAtVtx"};
  TTreeReaderArray<float> eledPhiAtVtx = {fReader, "eledPhiAtVtx"};
  TTreeReaderArray<float> eledEtaAtCalo = {fReader, "eledEtaAtCalo"};
  TTreeReaderArray<float> eleSigmaIEtaIEtaFull5x5 = {fReader, "eleSigmaIEtaIEtaFull5x5"};
  TTreeReaderArray<float> eleSigmaIPhiIPhiFull5x5 = {fReader, "eleSigmaIPhiIPhiFull5x5"};
  TTreeReaderArray<int> eleConvVeto = {fReader, "eleConvVeto"};
  TTreeReaderArray<int> eleMissHits = {fReader, "eleMissHits"};
  TTreeReaderArray<float> eleESEffSigmaRR = {fReader, "eleESEffSigmaRR"};
  TTreeReaderArray<float> elePFChIso = {fReader, "elePFChIso"};
  TTreeReaderArray<float> elePFPhoIso = {fReader, "elePFPhoIso"};
  TTreeReaderArray<float> elePFNeuIso = {fReader, "elePFNeuIso"};
  TTreeReaderArray<float> elePFPUIso = {fReader, "elePFPUIso"};
  TTreeReaderArray<float> elePFClusEcalIso = {fReader, "elePFClusEcalIso"};
  TTreeReaderArray<float> elePFClusHcalIso = {fReader, "elePFClusHcalIso"};
  TTreeReaderArray<float> elePFMiniIso = {fReader, "elePFMiniIso"};
  TTreeReaderArray<float> eleIDMVA = {fReader, "eleIDMVA"};
  TTreeReaderArray<float> eleIDMVAHZZ = {fReader, "eleIDMVAHZZ"};
  TTreeReaderArray<float> eledEtaseedAtVtx = {fReader, "eledEtaseedAtVtx"};
  TTreeReaderArray<float> eleE1x5 = {fReader, "eleE1x5"};
  TTreeReaderArray<float> eleE2x5 = {fReader, "eleE2x5"};
  TTreeReaderArray<float> eleE5x5 = {fReader, "eleE5x5"};
  TTreeReaderArray<float> eleE1x5Full5x5 = {fReader, "eleE1x5Full5x5"};
  TTreeReaderArray<float> eleE2x5Full5x5 = {fReader, "eleE2x5Full5x5"};
  TTreeReaderArray<float> eleE5x5Full5x5 = {fReader, "eleE5x5Full5x5"};
  TTreeReaderArray<float> eleR9Full5x5 = {fReader, "eleR9Full5x5"};
  TTreeReaderArray<int> eleEcalDrivenSeed = {fReader, "eleEcalDrivenSeed"};
  TTreeReaderArray<float> eleDr03EcalRecHitSumEt = {fReader, "eleDr03EcalRecHitSumEt"};
  TTreeReaderArray<float> eleDr03HcalDepth1TowerSumEt = {fReader, "eleDr03HcalDepth1TowerSumEt"};
  TTreeReaderArray<float> eleDr03HcalDepth2TowerSumEt = {fReader, "eleDr03HcalDepth2TowerSumEt"};
  TTreeReaderArray<float> eleDr03HcalTowerSumEt = {fReader, "eleDr03HcalTowerSumEt"};
  TTreeReaderArray<float> eleDr03TkSumPt = {fReader, "eleDr03TkSumPt"};
  TTreeReaderArray<float> elecaloEnergy = {fReader, "elecaloEnergy"};
  TTreeReaderArray<float> eleTrkdxy = {fReader, "eleTrkdxy"};
  TTreeReaderArray<float> eleKFHits = {fReader, "eleKFHits"};
  TTreeReaderArray<float> eleKFChi2 = {fReader, "eleKFChi2"};
  TTreeReaderArray<float> eleGSFChi2 = {fReader, "eleGSFChi2"};
  TTreeReaderArray<vector<float>> eleGSFPt = {fReader, "eleGSFPt"};
  TTreeReaderArray<vector<float>> eleGSFEta = {fReader, "eleGSFEta"};
  TTreeReaderArray<vector<float>> eleGSFPhi = {fReader, "eleGSFPhi"};
  TTreeReaderArray<vector<float>> eleGSFCharge = {fReader, "eleGSFCharge"};
  TTreeReaderArray<vector<int>> eleGSFHits = {fReader, "eleGSFHits"};
  TTreeReaderArray<vector<int>> eleGSFMissHits = {fReader, "eleGSFMissHits"};
  TTreeReaderArray<vector<int>> eleGSFNHitsMax = {fReader, "eleGSFNHitsMax"};
  TTreeReaderArray<vector<float>> eleGSFVtxProb = {fReader, "eleGSFVtxProb"};
  TTreeReaderArray<vector<float>> eleGSFlxyPV = {fReader, "eleGSFlxyPV"};
  TTreeReaderArray<vector<float>> eleGSFlxyBS = {fReader, "eleGSFlxyBS"};
  TTreeReaderArray<vector<float>> eleBCEn = {fReader, "eleBCEn"};
  TTreeReaderArray<vector<float>> eleBCEta = {fReader, "eleBCEta"};
  TTreeReaderArray<vector<float>> eleBCPhi = {fReader, "eleBCPhi"};
  TTreeReaderArray<vector<float>> eleBCS25 = {fReader, "eleBCS25"};
  TTreeReaderArray<vector<float>> eleBCS15 = {fReader, "eleBCS15"};
  TTreeReaderArray<vector<float>> eleBCSieie = {fReader, "eleBCSieie"};
  TTreeReaderArray<vector<float>> eleBCSieip = {fReader, "eleBCSieip"};
  TTreeReaderArray<vector<float>> eleBCSipip = {fReader, "eleBCSipip"};
  TTreeReaderArray<unsigned int> eleFiredSingleTrgs = {fReader, "eleFiredSingleTrgs"};
  TTreeReaderArray<unsigned int> eleFiredDoubleTrgs = {fReader, "eleFiredDoubleTrgs"};
  TTreeReaderArray<unsigned int> eleFiredL1Trgs = {fReader, "eleFiredL1Trgs"};
  TTreeReaderArray<unsigned short> eleIDbit = {fReader, "eleIDbit"};

};

#endif
