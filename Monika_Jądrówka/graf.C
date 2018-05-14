class CrossSection : public TObject {
    public:
        CrossSection(){
        fFile = new TFile("outCS1.root", "RECREATE");
        }
        void nuCrossSection(TString file, TString name);
        TFile *fFile;
};

void CrossSection::nuCrossSection(TString file, TString name)
{
    TTree *t1 = new TTree("muon neutrino CS", "muon neutrino CS");
    t1->ReadFile(file, "time1:time2:zliczenia");

    Float_t time1, time2, zliczenia ;
    t1->SetBranchAddress("time1", &time1);
    t1->SetBranchAddress("time2", &time2);
    t1->SetBranchAddress("zliczenia", &zliczenia);
    
    Float_t x[200], y[200];
    Float_t g=0;
    Int_t nentries = t1->GetEntries();
    for (Int_t i=0; i<nentries; i++){
        t1->GetEntry(i);
        g=(time1+time2)/2;
        x[i]=g;
        y[i]=zliczenia;
}

TCanvas *c1 = new TCanvas("c1", "#nu_{#mu,e}", 0,0,800,600);
//gPad->SetLogx();
TGraph *nuCS = new TGraph(nentries, x, y);
nuCS->Draw("AP*");
nuCS->SetMarkerStyle(21);
nuCS->GetXaxis()->SetTitle("czas");
nuCS->GetYaxis()->SetTitle("zliczenia");
//nuCS->GetXaxis()->SetLimits(0.1,500.);

Float_t intCS = nuCS->Integral();
cout<<"Integral: "<<intCS<<endl;

Float_t meanCS = nuCS->GetMean(2);
cout<<"Mean CS: "<<meanCS<<endl;
nuCS->SetName(name);
nuCS->SetTitle("CS");
nuCS->Write();

fFile->Write();

}

int main()
{
    CrossSection *sc = new CrossSection();
    sc->nuCrossSection("../data/muDecay.dat", "nuCS");
}
