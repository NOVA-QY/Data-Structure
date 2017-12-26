#include<iostream>
#include<cstdio>
#include<cstdlib>
#define STACK_INIT_SIZE 100
#define STACK_INCRE	10

int N;
int e;

//栈的结构体定义 
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

SqStack sq2;

//初始化建栈操作 
int InitStack(SqStack &s){
	s.base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!s.base)return 0;
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return 1;
}

//返回栈顶元素 
int GetTop(SqStack s,int &e){
	if(s.top==s.base)return 0;
	e=*(s.top-1);
	return 1;
}

//向栈内压入元素 
int Push(SqStack &s,int e){
	if(s.top-s.base>=s.stacksize){
		s.base=(int*)realloc(s.base,(s.stacksize+STACK_INCRE)*sizeof(int));
		if(!s.base)return 0;
		s.top=s.base+s.stacksize;
		s.stacksize+=STACK_INCRE;
	}
	*s.top++=e;
	return 1;
}

//取出栈顶元素 
int pop(SqStack &s,int &e){
	if(s.top==s.base)return 0;
	e=*--s.top;
	return 1;
}

//判空 
bool StackEmpty(SqStack S){
	if(S.base==S.top)
		return false;
	else
		return true;
}

//打印栈内元素 
void print(SqStack s){
	while(s.top!=s.base){
		printf("%d ",*(--s.top));
	}
	printf("\n");
}

//进制转换(转8进制) 
void conversion(){
	InitStack(sq2);
	scanf("%d",&N);
	while(N){
		Push(sq2,N%8);
		N=N/8;
	}
	while(sq2.base!=sq2.top){
		pop(sq2,e);
		printf("%d",e);
	} 
}

int main(){
	//测试基本操作函数 
	int n;
	SqStack sq;
	InitStack(sq);
	InitStack(sq2);
	while(scanf("%d",&n)!=EOF){
		Push(sq,n);
	}
	print(sq);
	//进制转换测试 
	conversion();
	return 0;
}
