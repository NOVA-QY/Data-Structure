/*
   广度优先遍历复杂度同深度优先遍历 
*/


#include <iostream>
#include "SparseGraph_model.h"
#include "DenseGraph_model.h"
#include "ReadGraph_model.h"
#include "Path_model.h"
#include "ShortestPath_model.h"

using namespace std;


int main() {

    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    Path<SparseGraph> dfs(g,0);
    cout<<"DFS : ";
    dfs.showPath(6);

	ShortestPath<SparseGraph> bfs(g,0);
	cout<<"BFS : ";
	bfs.showPath(6);
	
    return 0;
}
