# include <iostream>
using namespace std;


#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>


# include "DisplayMenu.h";
# include "VirusEvolution.h";
#include "AntiVirus.h";
#include "RestrictionSites.h";
#include "ViralPrediction.h";
#include "VirusTree.h";




void Display::displayMenu( )
{
	
	int choosenum;

	do
	{
	       
			
			 cout << "************************************************************" <<endl<<endl;
			 cout << "*                     WELCOME TO VIRUS LAB                   *" <<endl<<endl;
			
			 cout << "************************************************************" <<endl;
			 cout << "*            Please Select Your options to Continue        *" <<endl;
			 cout << "*              1 - Investigate Virus Evolution              *" <<endl;
			 cout << "*              2 - Design Anti-Viral Protein                *" <<endl;
			 cout << "*              3 - Design Restriction Sites                 *" <<endl;
			 cout << "*              4 - Viral Family Tree                        *" <<endl;
			 cout << "*              5 - Viral Prediction                         *" <<endl;
			 cout << "*                      6 - QUIT                             *" <<endl;
			  cout << "************************************************************" <<endl;
			
			 cin>>choosenum;

			

	 if(choosenum ==1)
		{
		char continueVirusEvolution =1;

		while (continueVirusEvolution !='0'){
		char matureDNA[50] = {'a','t','g','g','a','g','t','a','c','c','t','g','t','g','t',
		'g','g','a','a','a', 'g','a','a','g','c','a','a','c','c','a', 'c','c','a','c',
		't','c','t','a','t','t', 't','t','g','t','g','c','a','t','c','a'};
      
	//cout << "Give mature viral DNA : " <<endl <<
		//" hint:'a','t','g','g','a','g','t','a','c','c','t','g','t','g','t', 'g','g','a','a','a', 'g','a','a','g','c','a','a','c','c','a', 'c','c','a','c','t','c','t','a','t','t', 't','t','g','t','g','c','a','t','c','a' " << endl;

	Individual newIndividual(matureDNA);
	newIndividual.setPrimitive();

	cout << "############# ASEXUAL REPRODUCTION ##########################################"<<endl;
	cout << "Mature DNA sequence is "<<endl << " [ "; newIndividual.getMature(); cout << " ]" << endl;

	cout << "Primitive DNA sequence is "<<endl << " [ "; newIndividual.getPrimitive();  cout << " ]" << endl;

	int levelFitness = newIndividual.getFitness(); 

	cout << "Current fitness level is [ " << levelFitness * 2 << " ] ";  cout <<endl;
	cout << "#######################################################"<<endl;


	int generation=0;
	while(levelFitness < 50){
     newIndividual.asexualEvolve();
	 levelFitness = newIndividual.getFitness(); 
	 cout << "Currently evolving in Generation : "<< (generation +1)  << " Levelfitness is : " << levelFitness  * 2<< endl;
	 generation ++;
	}

		cout << "#######################################################"<<endl;
	cout << "Mature DNA sequence is "<<endl << " [ "; newIndividual.getMature(); cout << " ]" << endl;

	cout << "Primitive DNA sequence is "<<endl << " [ "; newIndividual.getPrimitive();  cout << " ]" << endl;

	cout << "Current fitness level is [ " << levelFitness *2 << " ] " << "Evolved : " <<  generation <<  " Generations " <<endl;
	cout << "#######################################################"<<endl;

	cout << "Do you want to try again ? press [1 to try again] and [0 to exit] "<<endl;
	cin>>continueVirusEvolution;

		}
		 
		}
	 if(choosenum ==2)
		 {
	    
        char continueAntiVirus ='Y';

		while (continueAntiVirus !='N'){
			 
	    char const aminoAcids [] = { 
        'R' , 'H' , 'K' , // positive charge
        'D' , 'E',      // negative
        'A', 'V', 'I', 'L', 'M','F','Y','W', // NON CHARGE
        'C','U','G','P',
        'S','T','N','Q' };


    string proteinSequences;
    cout << " Type the protein sequence of length 10 :"       <<endl <<
            " Possible aminoacids:  R-H-K-D-E-A-V-I-L-M-F-Y-W-C-U-G-P-S-T-N-Q " << endl;
   cout <<":" ; cin>> proteinSequences;
   
	ProteinInteraction protein0 (proteinSequences);

	cout<<endl;
	cout << " Generating protein ......" <<endl;

	cin.get();
    srand (time(NULL));
	
	int const length = 10;
    int temp = 0;





	string randomprotein1;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein1 [length];
			int i = 0;
			while (i< length){
				randomProtein1[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein1a(randomProtein1, length); //converting char to string
			randomprotein1 = randomprotein1a;
			temp =ProteinInteraction::calCharge(randomprotein1a);
	}

	ProteinInteraction protein1 (randomprotein1);
	



	temp = 0;
	string randomprotein2;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein2 [length];
			
			int i = 0;
			while (i< length){
				randomProtein2[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein2a(randomProtein2, length); //converting char to string
			randomprotein2 = randomprotein2a;
			temp =ProteinInteraction::calCharge(randomprotein2a);
	}

	ProteinInteraction protein2 (randomprotein2);




	temp = 0;
	string randomprotein3;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein3 [length];
		
			int i = 0;
			while (i< length){
				randomProtein3[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein3a(randomProtein3, length); //converting char to string
			randomprotein3 = randomprotein3a;
			temp =ProteinInteraction::calCharge(randomprotein3a);
	}

	ProteinInteraction protein3 (randomprotein3);







	temp = 0;
	string randomprotein4;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein [length];

			int i = 0;
			while (i< length){
				randomProtein[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein1a(randomProtein, length); //converting char to string
			randomprotein4 = randomprotein1a;
			temp =ProteinInteraction::calCharge(randomprotein1a);
	}

	ProteinInteraction protein4 (randomprotein4);
	





	temp = 0;
	string randomprotein5;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein [length];

			int i = 0;
			while (i< length){
				randomProtein[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein1a(randomProtein, length); //converting char to string
			randomprotein5 = randomprotein1a;
			temp =ProteinInteraction::calCharge(randomprotein1a);
	}

	ProteinInteraction protein5 (randomprotein5);
	





	temp = 0;
	string randomprotein6;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein [length];

			int i = 0;
			while (i< length){
				randomProtein[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein1a(randomProtein, length); //converting char to string
			randomprotein6 = randomprotein1a;
			temp =ProteinInteraction::calCharge(randomprotein1a);
	}

	ProteinInteraction protein6 (randomprotein6);
	




	temp = 0;
	string randomprotein7;
	while (temp != protein0.calculateCharge()){ 

			char randomProtein [length];

			int i = 0;
			while (i< length){
				randomProtein[i] = aminoAcids[rand()% 21]; 
			i++;
			}
			string randomprotein1a(randomProtein, length); //converting char to string
			randomprotein7 = randomprotein1a;
			temp =ProteinInteraction::calCharge(randomprotein1a);
	}

	ProteinInteraction protein7 (randomprotein7);
	

	
	protein0.createInteraction ( protein1, protein2, protein3, protein4,  protein5, protein6, 
		 protein7);
	cout <<endl ;

	cout<< " Target Protein is " <<protein0.getprotein() << " with charge - " << protein0.calculateCharge() << endl <<
		   " And possible interactors are  " << endl <<endl;

	protein0.getInteractions();

	cout<<endl<<endl;
	cout<< "Calculating Confidence of interaction " <<endl;

	int confidence1 = abs (protein0.calculateConfidence()- protein1.calculateConfidence());
	int confidence2 = abs (protein0.calculateConfidence()- protein2.calculateConfidence());
	int confidence3 = abs (protein0.calculateConfidence()- protein3.calculateConfidence());
	int confidence4 = abs (protein0.calculateConfidence()- protein4.calculateConfidence());
	int confidence5 = abs (protein0.calculateConfidence()- protein5.calculateConfidence());
	int confidence6 = abs (protein0.calculateConfidence()- protein6.calculateConfidence());
	int confidence7 = abs (protein0.calculateConfidence()- protein7.calculateConfidence());

		cout << ":"<<protein1.getprotein() <<" -Confidence- " << 100 - confidence1 << "%" << endl ;
		cout << ":"<<protein2.getprotein() <<" -Confidence- "  <<100 - confidence2<< "%"  << endl ;
		cout << ":"<<protein3.getprotein() <<" -Confidence- " << 100 -confidence3<< "%"  << endl ;
		cout << ":"<<protein4.getprotein() <<" -Confidence- "  <<100 - confidence4<< "%" << endl ;
		cout << ":"<<protein5.getprotein() <<" -Confidence- "  << 100 -confidence5<< "%" << endl ;
		cout << ":"<<protein6.getprotein() <<" -Confidence- "  << 100 -confidence6<< "%"  << endl ;
	    cout << ":"<<protein7.getprotein() <<" -Confidence- " << 100 - confidence7<< "%"  << endl ;



	cout << "Do you want to try again ? press [Y to try again] and [N to exit] "<<endl;
	cin>>continueAntiVirus;

		}

			
		 }
	 if(choosenum ==3)
		 {
				DNASequence viralDNA;
	char dnaSeq; 
	string viralsequence =
    "atgagtgaagaggagcaaggctccggcactaccacgggctgcgggctgctagtatagagcaaatgctggccgccaacccaggcaagaccccgatcagccttctgcaggagtatgggacactgc" ;

	int i = 0;int nuc_a = 0, nuc_t=0 , nuc_g=0 , nuc_c =0;
	while ( i <viralsequence.length() ){
		viralDNA.push(viralsequence[i]); i++;
		}

	cout << " Viral DNA sequence is : " <<endl;
	i = 0;


	while ( i <viralsequence.length() ){
		viralDNA.pop(dnaSeq);
		cout << " " << dnaSeq;


		if      (dnaSeq =='a') nuc_a++ ;
		else if (dnaSeq =='t') nuc_t++ ;
		else if (dnaSeq =='g') nuc_g++ ;
		else  nuc_c++ ;




	i++;
	}

	

	cout << endl <<endl << " sequence composition are : " <<endl<<
		" a : " << nuc_a <<endl  <<
		" t : " << nuc_t <<endl  <<
		" g : " << nuc_g <<endl  <<
		" c : " << nuc_c <<endl<<endl;

	

	char choice = 'Y';

	while (choice =='y'||choice =='Y') {

	i=0;
	while ( i <viralsequence.length() ){
		viralDNA.push(viralsequence[i]); i++;
		}

	string nuc4; char nuc_1, nuc_2, nuc_3, nuc_4;
	cout << " Provide four nucletides cutting sites by your Enzyme: hint - cgtc in " <<endl <<" : " ;
	cin>>nuc4;
    nuc_1 = nuc4[0];
	nuc_2= nuc4[1];
	nuc_3 = nuc4[2];
	nuc_4= nuc4[3];
	cout << "  You provided : " <<nuc_1<<nuc_2<< nuc_3<< nuc_4<<endl;
	int count =0;
	i=0;
	int len = viralsequence.length();
	
		while ( i <len-4)
		{
	    viralDNA.pop(dnaSeq); len--;
		 if(dnaSeq ==nuc_1)
		 {
			  viralDNA.pop(dnaSeq);len--;
			  if(dnaSeq ==nuc_2)
			  {
			        viralDNA.pop(dnaSeq);len--;
					    if(dnaSeq == nuc_3)
						{
                           viralDNA.pop(dnaSeq);len--;
						  if(dnaSeq == nuc_4)
							  {count++;
						       viralDNA.pop(dnaSeq);len--;
							  }continue;
						}continue;
			  }continue;
		 }continue;
		 
		 
         i++; }


		if(count != 0){
		cout<<" Your Enzyme cuts at " <<nuc_1<<nuc_2<< nuc_3<< nuc_4<< "  " << count << " sites " <<endl;}
		else {cout << " No cutting sites " <<endl;}

		


		cout << " Do you want to continue [Y] or [N] ? " << endl << "  : " ;
		cin>>choice;
	}

		 
		 }
	  if(choosenum ==4)
		 {

    char choice = 'Y';

	while (choice =='y'||choice =='Y') {

	string Virus1 = "MASTER";
	string Virus2 = "Virus2";
	string Virus3 = "Virus3";
	string Virus4 = "Virus4";
	string Virus5 = "Virus5";
	string Virus6 = "Virus6";
	string Virus7 = "Virus7";
	string Virus8 = "Virus8";
	string Virus9 = "Virus9";
	string Virus10 = "Virus10";
	string Virus11 = "Virus11";
	


	char  dna1  [] = {'g','a','c','c','a','t','g','t','a','c','g','a','c','c','a','t','g','t','a','c','g','a','c','c','a','t','g','t','a','c'};
	char  dna2  [] = {'c','a','c','c','a','t','g','t','a','c','c','g','t','a','c','g','t','a','c','g','c','g','t','a','c','g','g','t','a','c'};
	char  dna3  [] = {'c','g','c','c','a','t','g','t','a','c','c','g','t','a','c','g','t','a','a','c','c','g','t','a','a','t','g','t','a','c'};
	char  dna4  [] = {'c','g','t','c','a','t','g','t','a','c','c','g','t','a','c','g','t','a','c','c','t','a','a','c','c','g','t','a','c','t'};
	char  dna5  [] = {'c','g','t','a','a','t','g','t','a','c','c','g','t','a','c','t','g','t','a','c','c','g','t','a','c','g','t','a','a','c'};
	char  dna6  [] = {'c','g','t','a','c','t','g','t','a','c','c','g','t','a','c','g','t','a','c','g','c','g','t','a','c','g','t','a','c','c'};
	char  dna7  [] = {'c','g','t','a','c','g','g','t','a','c','c','g','c','c','a','t','g','t','a','c','t','a','a','c','c','g','t','a','c','t'};
	char  dna8  [] = {'c','g','t','a','c','g','t','t','a','c','c','g','t','a','c','g','t','a','c','c','t','a','a','c','c','g','t','a','c','t'};
	char  dna9  [] = {'c','g','t','a','c','g','t','a','a','c','c','g','t','a','c','t','g','t','a','c','c','g','t','a','c','t','g','t','a','c'};
	char  dna10 [] = {'c','g','t','a','c','g','t','a','c','c','c','g','c','c','a','t','g','t','a','c','t','a','a','c','c','a','c','t','g','t'};
	char  dna11 [] = {'c','g','t','a','c','g','t','a','c','g','c','g','t','a','c','g','g','t','a','c','c','g','t','a','c','t','g','t','a','c'};


	double dna1_1 = 1; // max for itself
	double dna1_2_SI = calculateSimilarityIndex (dna1 ,  dna2 );
	double dna1_3_SI = calculateSimilarityIndex (dna1 ,  dna3 );
	double dna1_4_SI = calculateSimilarityIndex (dna1 ,  dna4 );
	double dna1_5_SI = calculateSimilarityIndex (dna1 ,  dna5 );
	double dna1_6_SI = calculateSimilarityIndex (dna1 ,  dna6 );
	double dna1_7_SI = calculateSimilarityIndex (dna1 ,  dna7 );
	double dna1_8_SI = calculateSimilarityIndex (dna1 ,  dna8 );
	double dna1_9_SI = calculateSimilarityIndex (dna1 ,  dna9 );
	double dna1_10_SI = calculateSimilarityIndex (dna1 ,  dna10);
	double dna1_11_SI = calculateSimilarityIndex (dna1 ,  dna11 );
	


	Tree virusTree;
	virusTree.insertNode(Virus1, dna1, dna1_1);
	virusTree.insertNode(Virus10,dna10,dna1_10_SI);
	virusTree.insertNode(Virus7, dna7, dna1_7_SI);
	virusTree.insertNode(Virus2, dna2, dna1_2_SI);
	virusTree.insertNode(Virus4, dna4, dna1_4_SI);
	virusTree.insertNode(Virus6, dna6, dna1_6_SI);
	virusTree.insertNode(Virus9, dna9, dna1_9_SI);
	virusTree.insertNode(Virus3, dna3, dna1_3_SI);
	virusTree.insertNode(Virus5, dna5, dna1_5_SI);
	virusTree.insertNode(Virus11,dna11, dna1_11_SI);
    virusTree.insertNode(Virus8, dna8, dna1_8_SI); 

	cout<<endl<<endl;

    cout<< "VIRUS NAME " << "      " << " SIMILARITY INDEX " << "                VIRUS DNA "<< "       " <<endl<<endl;
	virusTree.displayTree();


		cout << " Do you want to continue [Y] or [N] ? " << endl << "  : " ;
		cin>>choice;
	}


		 }
	  if(choosenum ==5)
		 {
	
   cout<<setprecision(4)<<fixed;
    
	int layers = 3;

	int neuronsperlayer [] = {2,2,1};

	NeuralNetwork mynet ( layers, neuronsperlayer );

	

	double input1 [] = { 0.7, 0.8}; // initial value to train neuron
	
	cout<< " Initializing the NETWORK ..."<<endl;

	mynet.setInput(input1);
	mynet.setRandomvalues();
	mynet.frontPropagation();

	mynet.checkvalues();

	double number = mynet.getOutput();

	int count =0;
	
	cout<<endl<<endl;
	cout <<" Now Training ..." <<endl;


	srand(time(NULL));

	while((!(number == 1)||!(number == 0)) && !(count==100)){

		count +=1;

	double x = ((double) rand() / RAND_MAX) * (0.9-(0.0)) + (0.0);
	double y = ((double) rand() / RAND_MAX) * (0.9-(0.0)) + (0.0);

	double target;

	if(x >0.5 && y >0.5){
		target = 1;}
	else if(x <0.49 && y <0.49){target = 0;}
	else target = 1;


    double input9 [] = { x, y};

	mynet.setInput(input9);
	mynet.frontPropagation();
	mynet.trainNet(target);
	number = mynet.getOutput();

	

	cout<< "   Input :   " << x <<" :: "<<y<< "    Target :  " << target <<"    "<< "   Prediction :   " << number<<endl;

	}

	char choice ='Y';
	while (choice !='N'){

	cout<<endl<<endl;
	cout << " Testing ... " <<endl;
	
	double testA; 
	double testB;

	cout<<" Give Test A  value : " ; cin>>testA;
	cout<<" Give Test B  value : " ; cin>>testB;

    double input9 [] = { testA, testB};

	mynet.setInput(input9);
	mynet.frontPropagation();
	
	number = mynet.getOutput();

	cout << " Prediction score is "<< number <<endl;
		
	if( number <=0.49) cout << " Virus not detected ! "<<endl;
	else if (  number >= 0.50 ) cout << " Virus detected ! "<<endl;
	else cout << " Cannot Determine ! "<<endl;

	cout << " Do you want to continue [Y] or [N] ? " << endl << "  : " ;
	cin>>choice;
	}
		 }
	}
	 while(choosenum != 6);
}

