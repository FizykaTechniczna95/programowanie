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
            fFile = new TFile("lewo5.root", "RECREATE");
        }
        ~CrossSection(){}
        void nuCrossSection(TString file, TString name);
        void nuTest(TString file, TString name);
        void nuPrint();
        TFile *fFile;
};
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
void CrossSection::nuPrint()
{
    cout <<"Hura"<< endl;
}



//------------------------------------------------------------------------------------
void CrossSection::nuTest(TString file, TString name)
{
    Int_t verbose = 0;
    gStyle->SetOptFit(1);


    TH2F *h2 = new TH2F("Test","Test",100,-100,20,800,0,3000);

    TTree *t1 = new TTree("muon neutrino cross section", "muon neutrino cross section");
    t1->ReadFile(file, "ch1:ch2:en");
    //t1->Write();

    Float_t ch1,ch2,en;
    t1->SetBranchAddress("ch1",   &ch1);
    t1->SetBranchAddress("ch2",   &ch2);
    t1->SetBranchAddress("en",    &en);

    Float_t g = 0;
    Int_t nentries = t1->GetEntries();
    std::cout <<"Nentries: "<< nentries << endl;

    for (Int_t i=0; i<nentries; i++) {
        t1->GetEntry(i);

        g=(ch2+ch1)/2;
        h2->Fill(g,en);

      // std::cout << "(E, en)\t" << g <<"\t"<< en << endl;
    }

    h2->Draw();
    h2->Fit("gaus");
    h2->SetName(name);
    h2->Write();
}

//------------------------------------------------------------------------------------
void CrossSection::nuCrossSection(TString file, TString name)
{
    Int_t verbose = 0;
    gStyle->SetOptFit(1);

    TTree *t1 = new TTree("muon neutrino cross section", "muon neutrino cross section");
    t1->ReadFile(file, "energy1:energy2:cs");
    //t1->Write();

    Float_t energy1,energy2,cs;
    t1->SetBranchAddress("energy1",   &energy1);
    t1->SetBranchAddress("energy2",   &energy2);
    t1->SetBranchAddress("cs", &cs);

    Float_t x[200], y[200], xe[200], ye[200];
    Float_t g = 0;
    Int_t nentries = t1->GetEntries();
    std::cout <<"Nentries: "<< nentries << endl;
    //std::cout << "(E, cs)\t" << x[0] <<"\t"<< y[0] << endl;
    for (Int_t i=0; i<nentries; i++) {
        t1->GetEntry(i);
        

        g=(energy2+energy1)/2;
        x[i]=g;
        xe[i] = 0;
        y[i]=cs; 
        ye[i]=TMath::Sqrt(cs);

       // std::cout << "(E, cs)\t" << x[i] <<"\t"<< y[i] << endl;
    }

    TCanvas *c1 = new TCanvas("c1","#nu_{#mu,e} from CNGS",0,0,600,800);
    //gPad->SetLogx();

    c1->Divide(1,2);


    c1->cd(1);
    TGraph *nuCS = new TGraph(nentries, x, y);
    nuCS->Draw("AP");
    nuCS->GetXaxis()->SetTitle("E_{#nu} [GeV]");
    nuCS->GetYaxis()->SetTitle("#nu cross secion/E_{#nu} (10^{-38}cm^{2}/GeV)");
    nuCS->Fit("pol2");

    c1->cd(2);
    TGraphErrors *nuCSe = new TGraphErrors(nentries, x, y, xe, ye);
    nuCSe->Draw("AP");
    nuCSe->GetXaxis()->SetTitle("E_{#nu} [GeV]");
    nuCSe->GetYaxis()->SetTitle("#nu cross secion/E_{#nu} (10^{-38}cm^{2}/GeV)");



    //nuCS->GetXaxis()->SetLimits(0.1, 500.);
    Float_t intCS = nuCS->Integral();
    std::cout <<"Integral CS:\t"<< intCS << endl;
    Float_t meanCS = nuCS->GetMean(2);
    std::cout <<"Mean CS:\t"<< meanCS << endl;

    TString name01 = name + "01";
    nuCS->SetName("test");
    nuCS->SetTitle("#u_{#mu}CC cross section per nucleon");
    nuCS->Write();

    nuCSe->SetName(name);
    nuCSe->SetTitle("#nu_{#mu}CC cross section per nucleon");
    nuCSe->Write();

    c1->SaveAs("cs01.png");

    fFile->Write();
}
//------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------
int main()
{
    CrossSection *sc = new CrossSection();
    //sc->nuCrossSection("data/nuCrossSection.csv",   "nuCS");
    //sc->nuCrossSection("data/nuCrossSectionMD.csv", "nuCS2");
    //sc->nuCrossSection("data/nuCrossSectionFL.csv", "nuCS3");
    //sc->nuCrossSection("data/muDecay.dat",   "nuCS5");
    sc->nuTest("zrodlo_prawo15_1_1.txt", "test01");
    sc->nuTest("zrodlo_prawo15_1_2.txt", "test02");
    sc->nuTest("zrodlo_lewo5_1_3.txt", "test03");
    sc->nuPrint();
}
