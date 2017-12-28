#include<iostream>
#include"SparseGraph_model.h"
#include"DenseGraph_model.h"
#include"ReadGraph_model.h"
#include"Component_model.h"

using namespace std;

int main(){
	
	//TestG1.txt
	string filename1="testG1.txt";
	SparseGraph g1=SparseGraph(13,false);
	ReadGraph<SparseGraph> readGraph1(g1,filename1);
	Component<SparseGraph> component1(g1);
	cout<<"TestG1.txt,Component Count: "<<component1.count()<<endl;
	
	cout<<endl;
	
	//testG2.txt
	string filename2="testG2.txt";
	DenseGraph g2=DenseGraph(7,false);
	ReadGraph<DenseGraph> readGraph2(g2,filename2);
	Component<DenseGraph> component2(g2);
	cout<<"TestG2.txt,Component Count: "<<component2.count()<<endl;
	return 0;
	
}
