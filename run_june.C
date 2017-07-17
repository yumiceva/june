void run_june() {

  TStopwatch t; 
  t.Start(); 

  gROOT->LoadMacro("Muon.cc+");
  gROOT->LoadMacro("MuonSelector.cc+");
  gROOT->LoadMacro("MuonHistos.cc+");
  gROOT->LoadMacro("Electron.cc+");
  gROOT->LoadMacro("ElectronSelector.cc+");
  //gROOT->LoadMacro("ElectronHistos.cc+");
  gROOT->LoadMacro("Jet.cc+");
  gROOT->LoadMacro("JetSelector.cc+");
  gROOT->LoadMacro("JetHistos.cc+");

  gROOT->LoadMacro("PUReweight.cpp+");

  //int nthreads = 4;
  //ROOT::EnableImplicitMT(nthreads);
  
  TChain* chain = new TChain("ggNtuplizer/EventTree");

  chain->AddFile("root://cmsxrootd.fnal.gov//store/user/yumiceva/ntuples_2016/TTbar.root");
  chain->Process("june.C++","output:histos_ttbar.root:endoutput PUinput:root://cmsxrootd.fnal.gov//store/user/yumiceva/ntuples_2016/TTbar.root:endPUinput");

  //chain->AddFile("/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root");
  //chain->Process("june.C++","output:histos_ttbar_100k.root:endoutput PUinput:/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root:endPUinput");

  //TProof::Open("");
  //chain->SetProof();

  // maximum events chain->Process("june.C++","",20000);
  //chain->Process("june.C++","output:histos_ST_s.root:endoutput",10000);
  //chain->Process("june.C++","output:histos_ttbar_100k.root:endoutput PUinput:/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root:endPUinput");
  //chain->Process("june.C++","output:histos_ST_s.root:endoutput");

  t.Stop();
  t.Print();

}

