{
  TFile *f1 = TFile::Open("nuCrossSection.root");
  TH2F *test01 = (TH2F*) f1->Get("test01");
  TH2F *test02 = (TH2F*) f1->Get("test02");
  TH2F *test03 = (TH2F*) f1->Get("test03");


    test01->Draw();
    test02->Draw("same");
  
}
