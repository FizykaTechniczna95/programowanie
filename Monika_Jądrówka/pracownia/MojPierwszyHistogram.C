void MojPierwszyHistogram()
{
    TH1F *h1 = new TH1F ("h1", " Moj pierwszy histogram " ,100 , -3 ,3);
    TCanvas *c1 = new TCanvas ("c1","c1");
    FILE *fp = fopen("dane_hist.dat","r");
    Int_t IloscZliczen;
    Int_t bin = 1;
    while(!feof (fp) ){
        fscanf(fp ,"%d" ,& IloscZliczen );
        h1->SetBinContent(bin , IloscZliczen);
        bin++;
    }
    fclose(fp) ;
    h1->GetXaxis()->SetTitle(" Wartosc");
    h1->GetYaxis()->SetTitle("Ilosc Zliczen");
    h1->Draw("E");
    h1->Fit("gaus");
    c1->SaveAs("MojPierwszyHistogram.pdf");
}

