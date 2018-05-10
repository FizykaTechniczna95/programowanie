{
  TFile *f1 = TFile::Open("test.root");
  TH2F *hist1 = (TH2F*) f1->Get("hist1");
  TH2F *hist2 = (TH2F*) f1->Get("hist2");
  //TH2F *hist3 = (TH2F*) f1->Get("hist3");
  
  //hist1->SetlineColor("kgreen");


  hist1->Draw();
  hist2->Draw("same");
  //hist3->Draw();
}
