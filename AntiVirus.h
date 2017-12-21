#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>



class ProteinInteraction {

        string protein;
        int charge;
        ProteinInteraction * targets[7];

 
public:

	ProteinInteraction (string inprotein );

	string getprotein();

	int calculateCharge();

	void createInteraction ( ProteinInteraction &protein1, ProteinInteraction &protein2, 
		ProteinInteraction &protein3,ProteinInteraction &protein4, ProteinInteraction &protein5, ProteinInteraction &protein6, 
		ProteinInteraction &protein7 
		);

	void getInteractions ();


	//based on amino acid propensities calculate interaction confidence: 
	//Large aromatic residues (Tyr-Y, Phe-F and Trp-W) and beta-branched amino acids (Thr-T, Val-V, Ile-I) are favored
	 int calculateConfidence ( );

    


static int calCharge(string protein);  };