#include "VirusTree.h";

	Tree::Tree(){
		root = nullptr;
	}


	void Tree::insertNode(string name, char dnaSeq[] , double index )
	{
		Node * newNode = new Node;

		newNode->virusName = name;

		for( int i = 0; i<30; i++){
            newNode->dnaSequence[i] = dnaSeq[i];
		}
		
	    newNode->SI= index;
		newNode->left= nullptr;
		newNode->right = nullptr;


		insertion(root, newNode);

	}


	void Tree::insertion ( Node *&root, Node *& newNode){

		if(root==nullptr)
		{
			root = newNode;
		}
		else if ( root->SI > newNode->SI ){
			insertion ( root->left, newNode);
		}
		else
			insertion ( root->right, newNode);
	}


	void Tree::displayTree(){

		display(root);
	}

	void Tree::display( Node *root){

		if(root != nullptr){
		  
		  display(root->right);
          for(int i =0 ; i<7; i++){
		  cout << root->virusName[i];
		  } 
		  cout << "               " ;
		  cout<<setprecision (2) << fixed <<root->SI<< "              "; 
		  for(int i =0 ; i<30; i++){
		  cout << root->dnaSequence[i];
		  }
		  cout<<endl<<endl;
		  
		  display(root->left);

		}
	}


	double calculateSimilarityIndex (char dna1[] , char dna2[] ) {

	double value =0;


	char mat [31][31];

	mat[0][0] =0;

	for ( int i =0; i <30; i++){

		mat[i+1][0]=dna1[i];
		mat[0][i+1]=dna2[i];
	}

	for ( int i =0; i <30; i++){

		
		if (mat[i+1][0]!= mat[0][i+1])

		{
			mat[i+1][i+1]=-10;
			
		}

		if (mat[i+1][0]== mat[0][i+1]) 
		{
			mat[i+1][i+1]=10;
		
		}
		else{
			mat[i+1][i+1]=0;
		
			
		}

	}

	for ( int i =0; i <30; i++){

		
		value = (value + (int)mat[i+1][i+1]);

	}


	return (value/300);

}