void run_june() {

  gROOT->LoadMacro("Muon.cc+");
  gROOT->LoadMacro("MuonSelector.cc+");
  gROOT->LoadMacro("MuonHistos.cc+");
  gROOT->LoadMacro("Jet.cc+");
  gROOT->LoadMacro("JetHistos.cc+");


  //int nthreads = 4;
  //ROOT::EnableImplicitMT(nthreads);
  
  TChain* chain = new TChain("ggNtuplizer/EventTree");
  chain->AddFile("/eos/uscms/store/user/troy2012/ntuples_2016/ST_s.root");
  // maximum events chain->Process("june.C++","",20000);
  chain->Process("june.C++","output:histos_ST_s.root:endoutput",5000);

}

