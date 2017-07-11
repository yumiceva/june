
#ifndef MuonHistos_H
#define MuonHistos_H

//#include "BaseHistos.h"
          //#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <TTreeReader.h>
//#include <TTreeReaderValue.h>
//#include <TTreeReaderArray.h>

#include "Muon.h"
#include <map>
#include <string>

#include "TNamed.h"
#include "TH1F.h"

class TCollection;

using namespace std;

class MuonHistos: public TNamed 
{

public:
  MuonHistos() : fhtmp(0) {}
  MuonHistos( const char *name );
  MuonHistos( MuonHistos& rhs );
  ~MuonHistos();

  //void Fill(int imu, std::map< int, float > uservar = std::map< int, float > () );
  //void Make();
  //Long64_t Merge(TCollection *li);
  //void MakeHistograms();
  void Book(string hname, string htitle, int nbins, double xlow, double xhigh, const char* xlabel, const char* ylabel) {

    TH1F* h = new TH1F(hname.c_str(), htitle.c_str(), nbins, xlow, xhigh);
    h->GetXaxis()->SetTitle(xlabel);
    h->GetYaxis()->SetTitle(ylabel);
    h->SetDirectory(0);
    h->Sumw2();
    fhists[hname] = h;
  }
  void Fill(Muon p);
  Long64_t Merge(TCollection *list);
  std::map< std::string, TH1F*> GetMap() { return fhists; }

  ClassDef(MuonHistos,1);

private:
  std::string fprefix;
  TH1F *fhtmp;
  std::map< std::string, TH1F* > fhists;

};
#endif
