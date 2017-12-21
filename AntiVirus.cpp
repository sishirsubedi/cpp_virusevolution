# include "AntiVirus.h";


ProteinInteraction::ProteinInteraction (string inprotein ){
	
	protein = inprotein;

	}

string ProteinInteraction::getprotein(){
		return protein;
	}

	int ProteinInteraction::calculateCharge(){

    int length = protein.length();
    int charge= 0;
    int i = 0;
    while (i< length){
          
        if ( protein[i] =='R' || protein[i] =='H' ||protein[i] == 'K' ){ charge += 1;}
        else if ( protein[i] =='D' || protein[i] =='E') {charge -=1;}
        else if ( protein[i] =='S' || protein[i] =='T' ||protein[i] == 'N'  ||protein[i] == 'Q' ){ charge +=1;}
        else if ( protein[i] =='C' || protein[i] =='U' ||protein[i] == 'G' ||protein[i] == 'P' ) {charge +=1;}

        i++;
    }

   return charge ;

	}

	void ProteinInteraction::createInteraction ( ProteinInteraction &protein1, ProteinInteraction &protein2, 
		ProteinInteraction &protein3,ProteinInteraction &protein4, ProteinInteraction &protein5, ProteinInteraction &protein6, 
		ProteinInteraction &protein7 
		){

			targets[0] = &protein1;
			targets[1] = &protein2;
			targets[2] = &protein3;
			targets[3] = &protein4;
			targets[4] = &protein5;
			targets[5] = &protein6;
			targets[6] = &protein7;
			
	
	}

	void ProteinInteraction::getInteractions (){

		
		cout << ":"<< targets[0]->getprotein() <<" -charge- " << targets[0]->calculateCharge() << endl ;
		cout << ":"<<targets[1]->getprotein() <<" -charge- " << targets[1]->calculateCharge() << endl ;
		cout << ":"<<targets[2]->getprotein() <<" -charge- " << targets[2]->calculateCharge() << endl ;
		cout << ":"<<targets[3]->getprotein() <<" -charge- " << targets[3]->calculateCharge() << endl ;
		cout << ":"<<targets[4]->getprotein() <<" -charge- " << targets[4]->calculateCharge() << endl ;
		cout << ":"<<targets[5]->getprotein() <<" -charge- " << targets[5]->calculateCharge() << endl ;
		cout << ":"<<targets[6]->getprotein() <<" -charge- " << targets[6]->calculateCharge() << endl ;


	}


	//based on amino acid propensities calculate interaction confidence: 
	//Large aromatic residues (Tyr-Y, Phe-F and Trp-W) and beta-branched amino acids (Thr-T, Val-V, Ile-I) are favored
	 int ProteinInteraction::calculateConfidence ( ){

		 int i, ci=0;
		 i=0;
		 while( i< 10) { 

			 if (  protein[i] == 'G'){ci = ci + 1;}
			 else if ( protein[i] == 'P'){ci = ci +3;}
			 else if ( protein[i] == 'Y' ||protein[i] == 'F'||protein[i] == 'W') {ci = ci +3;}
			 else if ( protein[i] == 'T' ||protein[i] == 'V'||protein[i] == 'I' ){ci = ci +3;}
			 i++;
			 
		 }
		 return ci;
	}

	 
	int ProteinInteraction::calCharge(string protein){

    int length = protein.length();
    int charge= 0;
    int i = 0;
    while (i< length){
          
        if ( protein[i] =='R' || protein[i] =='H' ||protein[i] == 'K' ){ charge += 1;}
        else if ( protein[i] =='D' || protein[i] =='E') {charge -=1;}
        else if ( protein[i] =='S' || protein[i] =='T' ||protein[i] == 'N'  ||protein[i] == 'Q' ){ charge +=1;}
        else if ( protein[i] =='C' || protein[i] =='U' ||protein[i] == 'G' ||protein[i] == 'P' ) {charge +=1;}

        i++;
    }

	return charge ; }




