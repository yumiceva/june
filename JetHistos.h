
#ifndef JetHistos_H
#define JetHistos_H

//#include "BaseHistos.h"
          //#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <TTreeReader.h>
//#include <TTreeReaderValue.h>
//#include <TTreeReaderArray.h>

#include "Jet.h"
#include <map>
#include <string>

#include "TNamed.h"
#include "TH1F.h"

class TCollection;

using namespace std;

class JetHistos: public TNamed 
{

public:
  JetHistos() : fhtmp(0) {}
  JetHistos( const char *name );
  JetHistos( JetHistos& rhs );
  ~JetHistos();

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
  void Fill(Jet p);
  Long64_t Merge(TCollection *list);
  std::map< std::string, TH1F*> GetMap() { return fhists; }

  ClassDef(JetHistos,1);

private:
  std::string fprefix;
  TH1F *fhtmp;
  std::map< std::string, TH1F* > fhists;

};
#endif
