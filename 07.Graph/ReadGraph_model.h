#ifndef INC_04_READ_GRAPH_READGRAPH_H
#define INC_04_READ_GRAPH_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

template<typename Graph>
class ReadGraph{

public:
	ReadGraph(Graph &graph,const string &filename){
		ifstream file(filename.c_str());		//读入文件 
		string line;					//按行读取 
		int V,E;
		
		assert(file.is_open());			//确认文件已经打开 
		
		assert(getline(file,line));		//确认读取成功
		stringstream ss(line);			//字符流输入 
		ss>>V>>E;						//字符流解析点数、边数
		
		assert(V==graph.V());
		
		//读入边 
		for(int i=0;i<E;i++){
			assert(getline(file,line));
			stringstream ss(line);
			
			int a,b;
			ss>>a>>b;
			//确保a、b不越界 
			assert(a>=0&&a<V);
			assert(b>=0&&b<V);
			graph.addEdge(a,b);
			
		}
		 
	}	
	
};

#endif //INC_04_READ_GRAPH_READGRAPH_H
