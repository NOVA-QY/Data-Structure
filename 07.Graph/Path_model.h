/*
	Path(深度优先寻路)：
	1.复杂度
		SparseGraph   O(V+E)
		DenseGraph    O(V^2) 
	2.可以用来检测一个图中是否有环 
*/

#ifndef INC_06_FINDING_A_PATH_PATH_H
#define INC_06_FINDING_A_PATH_PATH_H

#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;


template <typename Graph>
class Path{

private:
    Graph &G;
    int s;
    bool* visited;
    int * from;

    void dfs( int v ){

        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() ){
            if( !visited[i] ){
                from[i] = v;		//记录前驱 
                dfs(i);
            }
        }
    }

public:
    Path(Graph &graph, int s):G(graph){

        // 算法初始化
        assert( s >= 0 && s < G.V() );

        visited = new bool[G.V()];
        from = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        // 寻路算法
        dfs(s);
    }

    ~Path(){

        delete [] visited;
        delete [] from;
    }

    bool hasPath(int w){
        assert( w >= 0 && w < G.V() );
        return visited[w];
    }

	//倒序寻路 
    void path(int w, vector<int> &vec){

        stack<int> s;

        int p = w;
        while( p != -1 ){	//直到找到源节点(未被赋值) 
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while(!s.empty()){
        	vec.push_back(s.top());
        	s.pop();
		}
        
    }

    void showPath(int w){

        vector<int> vec;
        path( w , vec );
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size() - 1 )	//判断是否为最后一个元素 
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
};

#endif //INC_06_FINDING_A_PATH_PATH_H

