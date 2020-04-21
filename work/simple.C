TString infile = "testg.fzd";
void simple( size_t n_events = 1000, const char *filename = 0 )
{

   if (filename) infile = filename;

   gROOT->LoadMacro("bfc.C");
   bfc(0, "fzin agml sdt20181215", infile );

   gSystem->Load("libStarClassLibrary.so");
   gSystem->Load("libStBichsel.so");
   gSystem->Load( "libStEvent.so" );
   gSystem->Load("libStHijingAna.so");

   if ( filename ) cout << filename << endl;

   // Create genfit forward track maker and add it to the chain before the MuDst maker
   StHijingAna *gmk = new StHijingAna();
   // chain->AddAfter( "0Event", gmk );

   // And initialize it, since we have already initialized the chain
   gmk->Init();

   // Do an ls to be sure
   chain->ls(3);

   size_t count = 0;

   // Loop over all events in the file...
   int stat = 0;

   while (stat == 0 && count < n_events) {

      cout << "===============================================================================" << endl;
      cout << "===============================================================================" << endl;
      cout << endl << endl;
      cout << "Processing event number " << count++ << endl << endl;
      cout << "===============================================================================" << endl;
      cout << "===============================================================================" << endl;

      chain->Clear();
      stat =    chain->Make();

      if (stat) break;
   
   }

   cout << "HERE IS FINISH" << endl;
   gmk->Finish();

   cout << "END of simple.C" << endl;


}
