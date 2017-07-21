#define june_cxx
// The class definition in june.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("june.C")
// root> T->Process("june.C","some options")
// root> T->Process("june.C+")
//


#include "june.h"
#include <TH2.h>
#include <TStyle.h>
#include "TLorentzVector.h"

#include "Muon.h"
#include "MuonSelector.h"
#include "Electron.h"
#include "ElectronSelector.h"
#include "Jet.h"
#include "JetSelector.h"

bool operator<( const TLorentzVector& tlv1, const TLorentzVector& tlv2 ) { return tlv1.Pt() < tlv2.Pt(); }
bool operator<( Jet& j1, Jet& j2 ) { TLorentzVector tlv1 = j1.getP4(); TLorentzVector tlv2 = j2.getP4(); return tlv1.Pt() < tlv2.Pt(); }

void june::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   cout << "================== BEGIN JOB" << endl;
   cout << "Run with options: " << option << endl;

}

void june::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   hpv = new TH1F("pv","Vertices",40,0,40);
   hpvReweight = new TH1F("pvreweight","Vertices",40,0,40);
   mu1Histos = new MuonHistos("mu1"); // leading muon
   jet1Histos = new JetHistos("jet1");
   jet2Histos = new JetHistos("jet2");

   /* TObjArray* list = fChain->GetListOfFiles();
   TIterator* iter = list->MakeIterator();
   TObject* obj = 0;
   while ((obj = iter->Next())) {
     TString fileName(obj->GetTitle());
     cout << fileName << endl;
   }
   */

   // Counters --------------------------------------------------------------------------
   counterlabels = {"begin",
                    "HLT",
                    "PV",
                    "TightMuon",
                    "vetoLooseMuon",
                    "vetoLooseElectron",
                    "3jets",
                    "4jets",
                    "gt5jets",
                    "1btag",
                    "2btag",
                    "gt3btag"
   };

   for ( vector<string>::iterator ii = counterlabels.begin(); ii != counterlabels.end(); ++ii) {
     counter[*ii] = 0.;
   }
   //-------------------

   TString pufilename = "purewight.root";
   if ( option.Contains("PUinput:") )
     {
       pufilename = option( option.Index("PUinput:"), option.Index(":endPUinput") );
       //pufilename.Remove(0,8);
       pufilename.ReplaceAll("PUinput:","");
       pufilename.ReplaceAll(":endPUinput","");

     }
   cout << "Pileup reweight MC input file: " << pufilename << endl;
   vector<string> fileNames;
   fileNames.push_back( pufilename.Data() );

   PUweighter = new PUReweight(1, fileNames, "Data_2016BCDGH_Pileup.root");
   
   cout << "Histogram containers created" << endl;
}

Bool_t june::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.


   fReader.SetEntry(entry);

   if ( entry%10000 == 0 )
     cout << "== Processing entry: " << entry << "  ==================="<<endl;
   
   counter["begin"]++;

   // reset weights
   //for ( map<string, float>::iterator it = fweights.begin(); it != fweights.end(); it++ )
   //for ( vector<float>::iterator ii = fweights.begin(); ii != fweights.end(); ++ii) {
   //  fweights[*ii] = 1;
   //}
   // Check if data or MC
   bool isMC = !( *isData );

   // check HLT
   if ( *HLTEleMuX >> 19 & 1 || *HLTEleMuX >> 20 & 1 ) counter["HLT"]++;
   else return kTRUE;

   // check for a good PV
   if ( *isPVGood ) {
     counter["PV"]++;
     // if MC get PU weight
     //if (isMC) {
     if (!isMC) {
       //cout << "isMC " << isMC << endl;
       vector<int> my_puBX;
       for (int i = 0, n =  puBX.GetSize(); i < n; ++i)
         {
           my_puBX.push_back( puBX[i] );
         }
       
       vector<float> my_puTrue;
       for (int i = 0, n =  puTrue.GetSize(); i < n; ++i)
         {
           my_puTrue.push_back( puTrue[i] );
         }
       fweights["PU"] = PUweighter->getWeight( (*nPUInfo), &my_puBX, &my_puTrue );
     }
     else fweights["PU"] = 1;
     //cout << " PU weight = " << fweights["PU"] << endl;
   }
   else return kTRUE;

   // define selectors
   //MuonSelector mu_loose_selector( fReader.GetTree(), entry, "loose");
   MuonSelector mu_loose_selector( fReader, "loose");
   MuonSelector mu_tight_selector( fReader.GetTree(), entry, "tight");
   ElectronSelector ele_veto_selector( fReader.GetTree(), entry, "loose");
   JetSelector jet_selector( fReader.GetTree(), entry, "tight", "CSVv2M");
   
   //cout << "got mu loose selector" << endl;
   std::vector< Muon > Loose_muons = mu_loose_selector.getList();
   std::vector< Muon > Tight_muons = mu_tight_selector.getList();
   std::vector< Electron > veto_electrons = ele_veto_selector.getList();
   std::vector< Jet > myjets = jet_selector.getList();

   //cout << "got loose muon list" << endl;
   //cout << "list size = " << Loose_muons.size() << endl;

   Muon tightMuon;
   Muon looseMuon;
   Electron vetoElectron;

   //cout << "loose size " << Loose_muons.size() << endl;
   //cout << "tight size " << Tight_muons.size() << endl;

   if ( Loose_muons.size() != 0 ) looseMuon = Loose_muons[0];
   else return kTRUE;

   if ( Tight_muons.size() == 1 ) tightMuon = Tight_muons[0];
   else return kTRUE;

   counter["TightMuon"]++;

   if ( Loose_muons.size() > 1 ) return kTRUE;
   counter["vetoLooseMuon"]++;

   if ( veto_electrons.size() > 0 ) return kTRUE;
   counter["vetoLooseElectron"]++;

   if ( myjets.size() < 3 ) return kTRUE;

   // Select 3 or more jets

   if ( myjets.size() == 3 ) counter["3jets"]++;

   if ( myjets.size() == 4 ) counter["4jets"]++;
   
   if ( myjets.size() >= 5 ) counter["gt5jets"]++;

   
   int Nbjets = 0;

   for ( unsigned int ijet = 0; ijet < myjets.size(); ++ijet) {
     if ( myjets[ijet].Isbtag() ) Nbjets++;
   }

   if ( Nbjets == 1 ) counter["1btag"]++;
   if ( Nbjets == 2 ) counter["2btag"]++;
   if ( Nbjets >= 3 ) counter["gt3btag"]++;

   // Compute M3
   //sort( myjets.begin(), myjets.end() );
   float M3 = -1;
   float sumpt = -1;
   int icomb = 0;
   do {
     //std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
     TLorentzVector tlv_M3 = myjets[0].getP4() + myjets[1].getP4() + myjets[2].getP4();
     if ( tlv_M3.Pt() >= sumpt )
       {
         sumpt = tlv_M3.Pt();
         M3 = tlv_M3.M();
       }
     icomb++;

   } while ( next_permutation(myjets.begin(), myjets.end() ) );

   float evtWeight = fweights["PU"];
   
   hpv->Fill ( *nVtx );
   hpvReweight->Fill( *nVtx, evtWeight );
   mu1Histos->Fill( tightMuon );
   jet1Histos->Fill( myjets[0] );
   jet2Histos->Fill( myjets[1] );

   //cout << "done filling the histo" << endl;
   
   return kTRUE;
}

void june::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void june::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  cout << "Terminate called" <<endl;

  TString option = GetOption();
  //cout << option<< endl;
  // get output
  TString filename = "histos.root";
  if ( option.Contains("output:") )
    {
      filename = option( option.Index("output:"), option.Index(":endoutput") );
      filename.Remove(0,7);
    }
  
  TFile *fFile = TFile::Open( filename, "RECREATE");
  cout << "Output root file: " << filename << endl;

  // Write histograms

  hpv->Write();
  hpvReweight->Write();

  map< string, TH1F*> hmap = mu1Histos->GetMap();
  for ( std::map< std::string, TH1F*>::iterator it= hmap.begin(); it != hmap.end(); ++it)
      {
        it->second->Write();
      }

  hmap = jet1Histos->GetMap();
  for ( std::map< std::string, TH1F*>::iterator it= hmap.begin(); it != hmap.end(); ++it)
    {
      it->second->Write();
    }
  
  hmap = jet2Histos->GetMap();
  for ( std::map< std::string, TH1F*>::iterator it= hmap.begin(); it != hmap.end(); ++it)
    {
      it->second->Write();
    }


  // Print cut flow --------------------------------------------------------------------
  cout << "== Cut flow:\n";
  //for ( map<string, float>::iterator it = counter.begin(); it != counter.end(); it++ )
  for ( vector<string>::iterator ii= counterlabels.begin(); ii != counterlabels.end(); ++ii)
    {
      //cout << format("%-25s %12.4f\n") % *ii % counter[*ii];
      cout << *ii << " " << counter[*ii] << endl;
    }

  //fSkim->Write();
  cout << "================== END JOB" << endl;
}
