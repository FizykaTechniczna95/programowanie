void MojPierwszyGraf()
{
    TCanvas *c1 = new TCanvas ("c1","c1");
    FILE *fp = fopen(".dat","r");
    Int_t x[100], y[100];
    Int_t licz = 0;
    while(!feof (fp)){
        fscanf(fp ,"%d %d", &x[licz] , &y[licz]);
        cout << x[licz] <<"\t"<< y[licz] << endl;
        licz++;
    }
    fclose(fp) ;

    TGraph *g1 = new TGraph (100 ,x,y) ;
    g1->GetXaxis()->SetTitle("X");
    g1->GetYaxis()->SetTitle("Y");
    g1->SetMarkerStyle (20) ;
    g1->Draw ("ap");
    g1->Fit("pol1");
    // TF1 *MojaFunkcja = new TF1 (" MojaFunkcja " , " pol1 " , 20 ,50);
    //g1->Fit("MojaFunkcja","R");
    c1->SaveAs(" MojPierwszyGraf.pdf");
 }
