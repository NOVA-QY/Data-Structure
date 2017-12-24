#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//定义链表结构体 
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

//定义队列结构体 
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化队列 
int InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)return 0;
	Q.front->next=NULL;
	return 1;
}

//销毁队列 
int DestoryQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return 1;
}

//插入元素
int EnQueue(LinkQueue &Q,int e){
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)return 0;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
} 

void print(LinkQueue &Q){
	QueuePtr t;
	t=Q.front->next;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
}

//删除队列中元素 
int DeQueue(LinkQueue &Q,int &e){
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回1
	//否则返回0 
	if(Q.front==Q.rear)return 0;
	QueuePtr p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return 1; 
}


int main(){
	int n;
	
	int e;
	LinkQueue q;
	InitQueue(q);
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		EnQueue(q,n);
	}
	DeQueue(q,e);
	print(q);
	return 0;
} 
