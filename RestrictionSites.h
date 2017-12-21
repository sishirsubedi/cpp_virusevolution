#ifndef RESTRICTIONSITES_H
#define RESTRICTIONSITES_H


#include <iostream>
#include <string>
using namespace std;

class DNASequence {
private:

	struct sequence {

		char nucleotide;
		sequence * next;
	};

	sequence * first;

public:

	DNASequence( );

	void push(char nuc);


	void pop ( char & nuc);

	bool isEmpty ();

   

};

#endif