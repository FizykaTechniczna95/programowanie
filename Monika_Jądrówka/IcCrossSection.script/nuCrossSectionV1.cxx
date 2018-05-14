/**
    Example script
    date: 2018.04.24
    v0.01 abubak

    root[0] .L nuCrossSection.cxx
    root[1] main();
**/


#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1.h"


//------------------------------------------------------------------------------------
class CrossSection : public TObject {
    public:
        CrossSection(){
            fFile = new TFile("output/nuCrossSection.root", "RECREATE");
        }
        ~CrossSection(){}
        void nuCrossSection(TString file, TString name);
        TFile *fFile;
};
//------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------
void CrossSection::nuCrossSection(TString file, TString name)
{
    Int_t verbose = 0;

    TTree *t1 = new TTree("muon neutrino cross section", "muon neutrino cross section");
    t1->ReadFile(file, "energy:cs");
    //t1->Write();

    Float_t energy,cs;
    t1->SetBranchAddress("energy",   &energy);
    t1->SetBranchAddress("cs", &cs);

    Float_t x[200], y[200];

    Int_t nentries = t1->GetEntries();
    std::cout <<"Nentries: "<< nentries << endl;
    //std::cout << "(E, cs)\t" << x[0] <<"\t"<< y[0] << endl;
    for (Int_t i=0; i<nentries; i++) {
        t1->GetEntry(i);

        x[i]=energy;
        y[i]=cs; 

       // std::cout << "(E, cs)\t" << x[i] <<"\t"<< y[i] << endl;
    }

    TCanvas *c1 = new TCanvas("c1","#nu_{#mu,e} from CNGS",0,0,800,600);
    gPad->SetLogx();


    c1->cd(1);
    TGraph *nuCS = new TGraph(nentries, x, y);
    nuCS->Draw("AP");
    nuCS->GetXaxis()->SetTitle("E_{#nu} [GeV]");
    nuCS->GetYaxis()->SetTitle("#nu cross secion/E_{#nu} (10^{-38}cm^{2}/GeV)");

    nuCS->GetXaxis()->SetLimits(0.1, 500.);
    Float_t intCS = nuCS->Integral();
    std::cout <<"Integral CS:\t"<< intCS << endl;
    Float_t meanCS = nuCS->GetMean(2);
    std::cout <<"Mean CS:\t"<< meanCS << endl;

    nuCS->SetName(name);
    nuCS->SetTitle("#nu_{#mu}CC cross section per nucleon");
    nuCS->Write();

    c1->SaveAs("cs01.png");

    fFile->Write();
}
//------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------
int main()
{
    CrossSection *sc = new CrossSection();
    sc->nuCrossSection("data/nuCrossSection.csv",   "nuCS");
    sc->nuCrossSection("data/nuCrossSectionMD.csv", "nuCS2");
    sc->nuCrossSection("data/nuCrossSectionFL.csv", "nuCS3");


}
