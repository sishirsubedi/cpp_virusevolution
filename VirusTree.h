#ifndef VIRUSTREE_H
#define VIRUSTREE_H


#include <iostream>
#include <vector>
using namespace std;
#include <iomanip>

class Tree {

	struct Node {

		
		char dnaSequence [30];
		double SI;
		string virusName;

		Node * left;
		Node * right;
	};

	Node * root;


	public:
	Tree();


	void insertNode(string name, char dnaSeq[] , double index );


	void insertion ( Node *&root, Node *& newNode);


	void displayTree();

	void display( Node *root);





};



double calculateSimilarityIndex (char dna1[] , char dna2[] );

#endif