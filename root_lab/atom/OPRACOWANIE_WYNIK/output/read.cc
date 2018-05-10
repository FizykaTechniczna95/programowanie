{
  TFile *f1 = TFile::Open("nuCrossSection_atom.root");
  TH2F *test01 = (TH2F*) f1->Get("test1");
  TH2F *test02 = (TH2F*) f1->Get("test2");
//  TH2F *test03 = (TH2F*) f1->Get("test3");

  test01->Draw();
  test02->Draw("same");
//  test03->Draw("same");
}
