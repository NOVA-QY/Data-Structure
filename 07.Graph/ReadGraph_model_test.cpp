#include<iostream>
#include "SparseGraph_model.h"
#include "DenseGraph_model.h"
#include "ReadGraph_model.h"

using namespace std;

int main(){
	
	string filename="testG1.txt";
	SparseGraph g1(13,false);
	ReadGraph<SparseGraph> readGraph(g1,filename);
	g1.show();
	
	return 0;
}
