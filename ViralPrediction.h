#ifndef VIRALPREDICTION_H
#define VIRALPREDICTION_H


#include <iostream>
#include <string>
using namespace std;

#include <time.h>
#include <cmath>
#include <math.h>  


struct Neuron {

	double initialValue;
	double *initialWeight;
	double delta;

};


struct Layer{

	int numNeurons;
	Neuron *neurons;
	

};


class NeuralNetwork {
	
	int numLayers;
	Layer *layers;
	

	public:

	
		
		double output;
		

	NeuralNetwork( int layernumber, int neuronnumber []);

   void setInput ( double inputvalue [] );


    void  setRandomvalues ();


	 void checkvalues();
	

	 void frontPropagation();



	 void trainNet (double target );

	 double getOutput ();

};






#endif