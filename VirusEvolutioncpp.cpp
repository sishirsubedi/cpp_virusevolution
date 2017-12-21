# include "VirusEvolution.h";

Individual::Individual ( char target[dnaLength]) {
		
		for ( int i =0; i<dnaLength ; i++)
		{
			mature[i] = target[i];
		}
		
	}


void Individual::getMature(){

	 for(int index=0; index<50; index++){
	     
	       cout << mature[index];
	   }


}


void Individual::setPrimitive(){
	
      srand ( time(NULL) );
	for ( int i =0; i<dnaLength ; i++)
		{
		char vDNA =  basesDNA[rand()% 4]; 
	  
			primitive[i] = vDNA;
		}


}


void Individual::getPrimitive(){

	 for(int index=0; index<dnaLength; index++){
	     
	       cout << primitive[index];
	   }


}



int Individual::getFitness( ){

	fitness =0;

	for(int index=0; index<50; index++){
	     
		if (primitive[index] == mature[index]){ fitness++; }
	   }

      return fitness;
}


void Individual::asexualEvolve ()  {

	for ( int i =0; i<dnaLength ; )
		{
			if(primitive[i] == mature[i]) { ++i; continue;}
			else{
		    char vDNA =  basesDNA[rand()% 4]; 
			primitive[i] = vDNA;
			++i;
			}

			}
		} 


	

