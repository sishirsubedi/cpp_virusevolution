#include "ViralPrediction.h";
#include <iomanip>  


	NeuralNetwork::NeuralNetwork( int layernumber, int neuronnumber [])
	{
		numLayers = layernumber;
		layers = new Layer[layernumber];
		int i , j ;

		for (i = 0; i<numLayers; i++){

			layers[i].numNeurons = neuronnumber[i];
			layers[i].neurons = new Neuron[neuronnumber[i]];

				for (j = 0; j<layers[i].numNeurons; j++){ 
		
					layers[i].neurons[j].initialValue = 1.1;
					layers[i].neurons[j].delta = 1.1;
					layers[i].neurons[j].initialWeight =  new double [neuronnumber [i]];

					}
		}



	}

   void NeuralNetwork::setInput ( double inputvalue [] ) {

   int i;
   for ( i = 0; i < layers[0].numNeurons; i++ )
    {
      layers[0].neurons[i].initialValue = inputvalue[i];      
    }
  
   }


    void NeuralNetwork::setRandomvalues ()
{
  srand(time(NULL));
  double temp;
  int i,j,k;
  for( i = 0; i < numLayers; i++ )
    {
      for( j = 0; j < layers[i].numNeurons; j++ )
	{
		for( k = 0; k< layers[i].numNeurons; k++ )
		{
		temp = ((double) rand() / RAND_MAX) * (1.0-(0.1)) + (0.1);
	    layers[i].neurons[j].initialWeight[k]  = temp;
		}

	}
    }

}


	 void NeuralNetwork::checkvalues(){

		 int i , j, k;

		for ( i =0; i< numLayers; i++){

		for ( j =0 ; j<layers[i].numNeurons; j++){ 
             cout << "Layer " << i << "  Neuron " << j <<" : " << layers[i].neurons[j].initialValue<<endl ;
		}
		}
	
	 }
	

	 void NeuralNetwork::frontPropagation(){
		 double temp =0.0; double sum = 0.0 ;
	

		for ( int i =1; i< numLayers; i++){

		for ( int j =0 ; j<layers[i].numNeurons; j++){ 

		for ( int k =0 ; k<layers[i-1].numNeurons; k++){ 
		
		temp = layers[i-1].neurons[k].initialValue * layers[i-1].neurons[k].initialWeight[j];
		sum += temp; 
		}
		 layers[i].neurons[j].initialValue = 1.0 / (1.0 + exp(- sum));
		 output = layers[i].neurons[j].initialValue ;
		 sum = 0.0;
		}
	 }

	 }


	 void NeuralNetwork::trainNet (double target ){

		
         double actual=output; //Actual value
        double delta= (target - actual) * actual * (1 - actual); //Function to compute error
		double error = (target - actual) * (target - actual) ; // square of error
		double learningrate =5;




		 for ( int i = numLayers-2; i==-1; i--){


		for ( int k =0 ; k<layers[i].numNeurons; k++){ 

		for ( int l =0 ; k<layers[i].numNeurons; l++){ 

		layers[i].neurons[k].initialWeight[l] += layers[i].neurons[k].initialValue * delta * learningrate * error; 
		
		// instead of this-- need to implement descent optimization algorithm

		}
		}
	}
		
	 }

	 double NeuralNetwork::getOutput () {

		 return layers[numLayers-1].neurons[0].initialValue;
	 }





