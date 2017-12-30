#include <iostream>
#include <iomanip>
#include "DenseGraph_model.h"
#include "SparseGraph_model.h"
#include "ReadGraph_model.h"
#include "LazyPrimMST_model.h"

using namespace std;

// 测试最小生成树算法
int main() {

    string filename = "testG3.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
    cout<<"Test Lazy Prim MST:"<<endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double> > mst = lazyPrimMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;

    cout<<endl;

    return 0;
}
