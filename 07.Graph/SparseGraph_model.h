#ifndef INC_03_VERTEX_ADJACENT_ITERATOR_SPARSEGRAPH_H
#define INC_03_VERTEX_ADJACENT_ITERATOR_SPARSEGRAPH_H

#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;

//稀疏图(邻接矩阵) 
class SparseGraph{

private:
	int n,m;
	bool directed;
	vector<vector<int> > g;
	 
public:
	SparseGraph(int n,bool directed){
		this->n=n;
		this->m=0;
		this->directed=directed;
		for(int i=0;i<n;i++)
			g.push_back(vector<int>());		//为简便使用向量实现
											//链表实现更方便删除操作 
																							
	}
	
	~SparseGraph(){}
	
	int V(){return n;}

	int E(){return m;}
	
	void addEdge(int v,int w){		//O(n)：取消平行边成本较高 
		assert(v>=0&&v<n);
		assert(w>=0&&w<n);
		
		g[v].push_back(w);
		if(v!=w&&!directed)		//1.无向图反向加边2.自环边只需要添加一次边 
			g[w].push_back(v);
			
		m++; 
	}
	
	bool hasEdge(int v,int w){
		assert(v>=0&&v<n);
		assert(w>=0&&w<n);
		for(int i=0;i<g[v].size();i++)	//O(n) 
			if(g[v][i]==w)
				return true;
		return false;
	} 
	
	//
	void show(){
		for(int i=0;i<n;i++){
			cout<<"vertex "<<i<<":\t";
			for(int j=0;j<g[i].size();j++)
				cout<<g[i][j]<<"\t";
			cout<<endl;
		}
	}
	
	
	//定义相邻节点迭代器
	class adjIterator{
	
	private:
		SparseGraph &G;	
		int v;
		int index; 
		
	public:
		adjIterator(SparseGraph &graph,int v):G(graph){
			this->v=v;
			this->index=0;
		}
		
		int begin(){
			index=0;	//显式置0(可能多此调用begin) 
			if(G.g[v].size()) 	//如果有元素，直接返回第一个元素 
				return G.g[v][index];
			return -1;
		}
		
		int next(){
			index++;
			if(index<G.g[v].size())
				return G.g[v][index];
			return -1;	 
		}
		
		bool end(){
			return index>=G.g[v].size();
		}
		
	}; 
	
	 
};

#endif //INC_03_VERTEX_ADJACENT_ITERATOR_SPARSEGRAPH_H

