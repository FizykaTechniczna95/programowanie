#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1.h"

class CrossSection : public TObject
{
  public:
    CrossSection() {fFile = new TFile("output/nuCrossSection.root","RECREATE");}
    ~CrossSection(){}
    void nuCrossSection(TString file, TString name);
    TFile *fFile;
};

void CrossSection::nuCrossSection(TString file, TString name)
{
    Int_t verbose = 0;
    TTree *t1 = new TTree("TTree test cross_section", "TTre test");
    t1 -> ReadFile(file, "tt1:tt2:cs");

    Float_t tt1, tt2, cs;
    t1 -> SetBranchAddress("tt1", &tt1);
    t1 -> SetBranchAddress("tt2", &tt2);
    t1 -> SetBranchAddress("cs", &cs);

    Float_t x[200], y[200];
    Float_t g = 0;    

    Int_t nentries = t1 -> GetEntries();

    for(Int_t i=0; i<nentries; i++)
    {
        t1 -> GetEntry(i);
        
        x[i] = (tt1+tt2)/2;
        y[i] = cs;
    }

    TCanvas *c1 = new TCanvas("c1", "Test", 0, 0, 800, 600);
    //gPad -> SetLogx();
    
    c1 ->cd(1);
    TGraph *nuCS = new TGraph(nentries, x, y);
    nuCS -> Draw("AP");
    nuCS -> GetXaxis() -> SetTitle("t [ns]");
    nuCS -> GetYaxis() -> SetTitle("N");
    nuCS->Fit("pol2");
    //nuCS -> GetXaxis() -> SetLimits(0.1, 500);
    
    Float_t intCS = nuCS -> Integral();
    std::cout<<"Integral_CS:\t"<<intCS<<endl;
    Float_t meanCS = nuCS -> GetMean(2);
    std::cout<<"Mean CS:\t"<<meanCS<<endl;

    nuCS -> SetName(name);
    nuCS -> SetTitle("TEST");
    nuCS -> Write();
}

int main()
{
    CrossSection *sc = new CrossSection();
    sc -> nuCrossSection("../../data/muDecay.dat", "nuCS3");
}
