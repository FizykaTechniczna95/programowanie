{
    TFile *f1 = TFile::Open("lewo25.root");

    TFile *f2 = TFile::Open("lewo15.root");

    TFile *f3 = TFile::Open("lewo5.root");

    TFile *f4 = TFile::Open("prawo5.root");

    TFile *f5 = TFile::Open("prawo15.root");

    TFile *f6 = TFile::Open("prawo25.root");


    TH2F *czas1 = (TH2F*) f1->Get("test03");
    test03->Draw();
    TH2F *czas2 = (TH2F*) f2->Get("test03");
    test03->Draw("same");
    TH2F *czas3 = (TH2F*) f3->Get("test03");
    test03->Draw("same");
    TH2F *czas4 = (TH2F*) f4->Get("test03");
    test03->Draw("same");
    TH2F *czas5 = (TH2F*) f5->Get("test03");
    test03->Draw("same");
    TH2F *czas6 = (TH2F*) f6->Get("test03");
    test03->Draw("same");
}
