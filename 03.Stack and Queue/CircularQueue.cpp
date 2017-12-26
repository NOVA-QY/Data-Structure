#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXSIZE 100
using namespace std;

int e;
int count;

typedef struct{
	int *base;
	int front;
	int rear;
//	int count;
}SqQueue;

int InitQueue(SqQueue &Q){
	//构造一个空队列
	Q.base=(int*)malloc(MAXSIZE*sizeof(int));
	if(!Q.base)return 0;	//存储空间分配失败 
	Q.front=Q.rear=0;
	return 1; 
}

int QueueLength(SqQueue Q){
	//返回Q的元素个数，即队列长度 
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int EnQueue(SqQueue &Q,int e){
	//插入元素e为Q的新的队尾元素
	if((Q.rear+1)%MAXSIZE==Q.front)return 0;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE; 
	return 1;
}

int DeQueue(SqQueue &Q,int &e){
	//若队列不空，删除Q的对头元素，用e返回其值
	//否则返回0 
	if(Q.front==Q.rear)return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 1;
}

void print(SqQueue cq){
	for(int i=0;i<count;i++){	//【1】 
		DeQueue(cq,e);
		printf("%d ",e);
	}
	printf("\n");
}

int main(){
	int n;
	SqQueue cq;
	InitQueue(cq);
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		EnQueue(cq,n);
	}
	count=QueueLength(cq);
	printf("%d\n",count);
	print(cq);
	return 0;
}
