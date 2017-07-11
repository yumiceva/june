//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 23 09:52:06 2017 by ROOT version 6.06/01
// from TTree EventTree/Event data (tag V08_00_24_00)
// found on file: /eos/uscms/store/user/troy2012/skims_13TeV_V08_26/ST_tW_top.root
//////////////////////////////////////////////////////////

#ifndef june_h
#define june_h

#include "MuonHistos.h"


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class june : public TSelector {
public :

  TH1F *hpv;
  MuonHistos *mu1Histos;

   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain
  
  //TTree  *fSkim = 0;

  bool first = true;

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> run = {fReader, "run"};
   TTreeReaderValue<Long64_t> event = {fReader, "event"};
   TTreeReaderValue<Int_t> lumis = {fReader, "lumis"};
   TTreeReaderValue<Bool_t> isData = {fReader, "isData"};
   TTreeReaderValue<Int_t> nVtx = {fReader, "nVtx"};
   TTreeReaderValue<Int_t> nGoodVtx = {fReader, "nGoodVtx"};
   TTreeReaderValue<Bool_t> isPVGood = {fReader, "isPVGood"};
   TTreeReaderValue<Float_t> rho = {fReader, "rho"};
   TTreeReaderValue<ULong64_t> HLTEleMuX = {fReader, "HLTEleMuX"};
   TTreeReaderArray<float> pdf = {fReader, "pdf"};
   TTreeReaderValue<Int_t> nPUInfo = {fReader, "nPUInfo"};
   TTreeReaderArray<int> nPU = {fReader, "nPU"};
   TTreeReaderArray<int> puBX = {fReader, "puBX"};
   TTreeReaderArray<float> puTrue = {fReader, "puTrue"};
   TTreeReaderValue<Int_t> nMC = {fReader, "nMC"};
   TTreeReaderArray<int> mcPID = {fReader, "mcPID"};
   TTreeReaderArray<float> mcPt = {fReader, "mcPt"};
   TTreeReaderArray<float> mcMass = {fReader, "mcMass"};
   TTreeReaderArray<float> mcEta = {fReader, "mcEta"};
   TTreeReaderArray<float> mcPhi = {fReader, "mcPhi"};
   TTreeReaderArray<int> mcGMomPID = {fReader, "mcGMomPID"};
   TTreeReaderArray<int> mcMomPID = {fReader, "mcMomPID"};
   TTreeReaderArray<float> mcMomPt = {fReader, "mcMomPt"};
   TTreeReaderArray<float> mcMomMass = {fReader, "mcMomMass"};
   TTreeReaderArray<float> mcMomEta = {fReader, "mcMomEta"};
   TTreeReaderArray<float> mcMomPhi = {fReader, "mcMomPhi"};
   TTreeReaderArray<int> mcParentage = {fReader, "mcParentage"};
   TTreeReaderArray<int> mcStatus = {fReader, "mcStatus"};
   TTreeReaderValue<Float_t> genMET = {fReader, "genMET"};
   TTreeReaderValue<Float_t> pfMET = {fReader, "pfMET"};
   TTreeReaderValue<Float_t> pfMETPhi = {fReader, "pfMETPhi"};
   TTreeReaderValue<Int_t> nPho = {fReader, "nPho"};
   TTreeReaderArray<float> phoEt = {fReader, "phoEt"};
   TTreeReaderArray<float> phoEta = {fReader, "phoEta"};
   TTreeReaderArray<float> phoPhi = {fReader, "phoPhi"};
   TTreeReaderArray<int> phohasPixelSeed = {fReader, "phohasPixelSeed"};
   TTreeReaderArray<int> phoEleVeto = {fReader, "phoEleVeto"};
   TTreeReaderArray<float> phoHoverE = {fReader, "phoHoverE"};
   TTreeReaderArray<float> phoSigmaIEtaIEtaFull5x5 = {fReader, "phoSigmaIEtaIEtaFull5x5"};
   TTreeReaderArray<float> phoPFChIso = {fReader, "phoPFChIso"};
   TTreeReaderArray<float> phoPFPhoIso = {fReader, "phoPFPhoIso"};
   TTreeReaderArray<float> phoPFNeuIso = {fReader, "phoPFNeuIso"};
   TTreeReaderValue<Int_t> nEle = {fReader, "nEle"};
   TTreeReaderArray<float> eleD0 = {fReader, "eleD0"};
   TTreeReaderArray<float> eleDz = {fReader, "eleDz"};
   TTreeReaderArray<float> elePt = {fReader, "elePt"};
   TTreeReaderArray<float> elePhi = {fReader, "elePhi"};
   TTreeReaderArray<float> eleSCEta = {fReader, "eleSCEta"};
   TTreeReaderArray<float> eleHoverE = {fReader, "eleHoverE"};
   TTreeReaderArray<float> eleEoverP = {fReader, "eleEoverP"};
   TTreeReaderArray<float> eledEtaAtVtx = {fReader, "eledEtaAtVtx"};
   TTreeReaderArray<float> eledPhiAtVtx = {fReader, "eledPhiAtVtx"};
   TTreeReaderArray<float> eleSigmaIEtaIEtaFull5x5 = {fReader, "eleSigmaIEtaIEtaFull5x5"};
   TTreeReaderArray<int> eleMissHits = {fReader, "eleMissHits"};
   TTreeReaderArray<float> elePFChIso = {fReader, "elePFChIso"};
   TTreeReaderArray<float> elePFPhoIso = {fReader, "elePFPhoIso"};
   TTreeReaderArray<float> elePFNeuIso = {fReader, "elePFNeuIso"};
   TTreeReaderArray<float> eleIDMVA = {fReader, "eleIDMVA"};
   TTreeReaderArray<float> eleIDMVAHZZ = {fReader, "eleIDMVAHZZ"};
   TTreeReaderArray<unsigned short> eleIDbit = {fReader, "eleIDbit"};
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
   TTreeReaderValue<Int_t> nJet = {fReader, "nJet"};
   TTreeReaderArray<float> jetPt = {fReader, "jetPt"};
   TTreeReaderArray<float> jetEn = {fReader, "jetEn"};
   TTreeReaderArray<float> jetEta = {fReader, "jetEta"};
   TTreeReaderArray<float> jetPhi = {fReader, "jetPhi"};
   TTreeReaderArray<float> jetRawPt = {fReader, "jetRawPt"};
   TTreeReaderArray<float> jetArea = {fReader, "jetArea"};
   TTreeReaderArray<float> jetpfCombinedMVAV2BJetTags = {fReader, "jetpfCombinedMVAV2BJetTags"};
   TTreeReaderArray<int> jetPartonID = {fReader, "jetPartonID"};
   TTreeReaderArray<float> jetGenJetPt = {fReader, "jetGenJetPt"};
   TTreeReaderArray<int> jetGenPartonID = {fReader, "jetGenPartonID"};
   TTreeReaderArray<float> jetGenPt = {fReader, "jetGenPt"};
   TTreeReaderArray<float> jetGenEta = {fReader, "jetGenEta"};
   TTreeReaderArray<float> jetGenPhi = {fReader, "jetGenPhi"};
   TTreeReaderValue<vector<bool>> jetPFLooseId = {fReader, "jetPFLooseId"};
   TTreeReaderArray<float> AK8JetCHF = {fReader, "AK8JetCHF"};
   TTreeReaderArray<float> AK8JetNHF = {fReader, "AK8JetNHF"};
   TTreeReaderArray<float> AK8JetCEF = {fReader, "AK8JetCEF"};
   TTreeReaderArray<float> AK8JetNEF = {fReader, "AK8JetNEF"};
   TTreeReaderArray<int> AK8Jetnconstituents = {fReader, "AK8Jetnconstituents"};


   june(TTree * /*tree*/ =0) { }
   virtual ~june() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(june,0);

};

#endif

#ifdef june_cxx
void june::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);

}

Bool_t june::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef june_cxx
