#include "RestrictionSites.h";





DNASequence::DNASequence( ) { first = nullptr;}

	void DNASequence::push(char nuc){

        sequence *newseq = new sequence;
		newseq->nucleotide = nuc;
		

		if(isEmpty()) {
		first = newseq;
		newseq->next = nullptr;
			}
	else {

		newseq->next = first;
		first = newseq;
		}
		
	}


	void DNASequence::pop ( char & nuc) {
	
		sequence * temp;

		if (isEmpty()) cout << "The sequence is empty" << endl;
		else {

			nuc =  first->nucleotide;
			temp = first->next;
			delete first;
			first=temp;

		}
	
	}

	bool DNASequence::isEmpty (){

		bool status;
	 
		if (!first)
			status = false;
		else
		   status = false;

		return status;

	
	
	
	}
