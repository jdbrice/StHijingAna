

void setGEANTLabels( TH1 * h){
	vector<string> ln = {"GAMMA","POSITRON","ELECTRON","NEUTRINO","MUON +","MUON -","PION 0","PION +","PION -","KAON 0 LONG","KAON +","KAON -","NEUTRON","PROTON","ANTIPROTON","KAON 0 SHORT","ETA","LAMBDA","SIGMA +","SIGMA 0","SIGMA -","XI 0","XI -","OMEGA -","ANTINEUTRON","ANTILAMBDA","ANTISIGMA -","ANTISIGMA 0","ANTISIGMA +","ANTIXI 0","ANTIXI +","ANTIOMEGA +","","","","","","","","","","","","","DEUTERON","TRITON","ALPHA","GEANTINO","HE3","Cerenkov"};

	for ( int i = 1; i < h->GetXaxis()->GetNbins(); i++ ){
		if ( i-1 >= ln.size() ) break;
		h->GetXaxis()->SetBinLabel( i, ln[i-1].c_str() );
	}

	h->GetXaxis()->SetTitle( "" );
}


void plots(){

	gStyle->SetOptStat(0);
	TCanvas * can = new TCanvas( "can", "", 1600, 900 );
	can->SetBottomMargin(0.2);

	TFile * f = new TFile( "all_Results.root" );

	TH1* hfwd_ge_pid = (TH1*)f->Get( "fwd_ge_pid" );


	setGEANTLabels( hfwd_ge_pid );
	hfwd_ge_pid->LabelsOption("v", "X");
	hfwd_ge_pid->SetLineColor(kBlack);
	hfwd_ge_pid->SetLineWidth(2);
	hfwd_ge_pid->SetFillColor(kRed);
	hfwd_ge_pid->Draw();

	TLatex tl;
	tl.SetTextFont(42);
	tl.SetTextSize( 24.0 / 360.0 );
	tl.DrawLatexNDC( 0.6, 0.8, "2.5 < #eta < 4.0" );

	hfwd_ge_pid->GetXaxis()->SetRangeUser(0, 51);

	gPad->SetLogy(1);
	can->Print( "out/fwd_ge_pid.pdf" );

	// **********
	TH1* hge_pid = (TH1*)f->Get( "ge_pid" );
	setGEANTLabels( hge_pid );
	hge_pid->LabelsOption("v", "X");
	hge_pid->SetLineColor(kBlack);
	hge_pid->SetLineWidth(2);
	hge_pid->SetFillColor(kRed);
	hge_pid->Draw();

	// TLatex tl;
	tl.SetTextFont(42);
	tl.SetTextSize( 24.0 / 360.0 );
	tl.DrawLatexNDC( 0.6, 0.8, "-2 < #eta < 2" );

	hge_pid->GetXaxis()->SetRangeUser(0, 51);

	gPad->SetLogy(1);
	can->Print( "out/ge_pid.pdf" );

	// **********
	TH1* hfwd_pt = (TH1*)f->Get( "pt" );
	hfwd_pt->GetXaxis()->SetRangeUser(0, 5.0);
	hfwd_pt->SetLineColor(kBlack);
	hfwd_pt->SetLineWidth(2);
	hfwd_pt->SetFillColor(kRed);
	hfwd_pt->Draw();

	// TLatex tl;
	tl.SetTextFont(42);
	tl.SetTextSize( 24.0 / 360.0 );
	tl.DrawLatexNDC( 0.6, 0.8, "2.5 < #eta < 4.0" );

	gPad->SetLogy(1);
	can->Print( "out/fwd_pt.pdf" );


	// **********
	TH1* hNtracks = (TH1*)f->Get( "Ntracks" );
	hNtracks->Rebin(5);
	hNtracks->SetLineColor(kBlack);
	hNtracks->SetLineWidth(2);
	hNtracks->SetFillColor(kRed);
	hNtracks->Draw();

	// TLatex tl;
	tl.SetTextFont(42);
	tl.SetTextSize( 24.0 / 360.0 );
	tl.DrawLatexNDC( 0.6, 0.8, "2.5 < #eta < 4.0" );

	gPad->SetLogy(1);
	can->Print( "out/Ntracks.pdf" );




}