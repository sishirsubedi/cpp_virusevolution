#ifndef VIRUSEVOLUTION_H
#define VIRUSEVOLUTION_H

#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>


static const char basesDNA[] = { 'a','t','g','c'};


class Individual {

    
private:

	const static int dnaLength = 50;
	char mature [dnaLength];

	char primitive[dnaLength];

	char primitive2[dnaLength]; // father dna


	int fitness;


public:

	Individual ( char target[dnaLength]);

	void getMature();

	void setPrimitive() ;

	void getPrimitive();

	int getFitness ();

	void asexualEvolve ();
	
};


#endif