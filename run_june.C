void run_june() {

  gROOT->LoadMacro("Muon.cc+");
  gROOT->LoadMacro("MuonSelector.cc+");
  gROOT->LoadMacro("MuonHistos.cc+");
  gROOT->LoadMacro("Electron.cc+");
  gROOT->LoadMacro("ElectronSelector.cc+");
  //gROOT->LoadMacro("ElectronHistos.cc+");
  gROOT->LoadMacro("Jet.cc+");
  gROOT->LoadMacro("JetSelector.cc+");
  gROOT->LoadMacro("JetHistos.cc+");


  //int nthreads = 4;
  //ROOT::EnableImplicitMT(nthreads);
  
  TChain* chain = new TChain("ggNtuplizer/EventTree");
  //chain->AddFile("root://cmsxrootd.fnal.gov//store/user/troy2012/ntuples_2016/ST_s.root");
  chain->AddFile("/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root");

  // maximum events chain->Process("june.C++","",20000);
  //chain->Process("june.C++","output:histos_ST_s.root:endoutput",10000);
  chain->Process("june.C++","output:histos_ttbar_100k.root:endoutput");
  //chain->Process("june.C++","output:histos_ST_s.root:endoutput");

}

