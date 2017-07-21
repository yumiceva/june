void run_june(string input = "", string output = "") {

  // start stopwatch
  TStopwatch t; 
  t.Start(); 

  // compile
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

  // check arguments
  if ( input == "" && output == "") {
    input = "/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root";
    output= "histos_ttbar_100k.root";
  }

  // define tree
  TChain* chain = new TChain("ggNtuplizer/EventTree");


  chain->AddFile(input.c_str());
  
  string options = "output:"+output+":endoutput"+" PUinput:"+input+":endPUinput";
  chain->Process("june.C+",options.c_str());

  //chain->AddFile("/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root");
  //chain->Process("june.C++","output:histos_ttbar_100k.root:endoutput PUinput:/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root:endPUinput");

  //TProof::Open("");
  //chain->SetProof();

  // maximum events chain->Process("june.C++","",20000);
  //chain->Process("june.C++","output:histos_ST_s.root:endoutput",10000);
  //chain->Process("june.C++","output:histos_ttbar_100k.root:endoutput PUinput:/uscms_data/d2/dnoonan/13TeV_TTGamma/TTGamma_SingleLeptFromTbar_100k.root:endPUinput");
  //chain->Process("june.C++","output:histos_ST_s.root:endoutput");

  // stop stopwatch
  t.Stop();
  t.Print();

}

