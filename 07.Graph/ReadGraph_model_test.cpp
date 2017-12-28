#include<iostream>
#include "SparseGraph_model.h"
#include "DenseGraph_model.h"
#include "ReadGraph_model.h"
using namespace std;

int main(){
	
	string filename="testG1.txt";
	SparseGraph g1(13,false);
	ReadGraph<SparseGraph> readGraph1(g1,filename);
	g1.show();
	
	cout<<endl;
	
	DenseGraph g2(13,false);
	ReadGraph<DenseGraph> readGraph2(g2,filename);
	g2.show();
	
	return 0;
}
