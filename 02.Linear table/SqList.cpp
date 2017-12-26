#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct{
	int *elem;	//指向线性表的指针 
	int length;	//表长 
	int listsize;	//表所占空间大小 
}SqList;

//初始化操作 
int initSqList(SqList &L){
	L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(SqList));	
	if(!L.elem)return 0;	//分配空间失败，则返回 
	L.length=0;		
	L.listsize=LIST_INIT_SIZE;
	return 1;
}

//插入操作 
int listInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)return 0;	//判断i的合法性  
	if(L.length>=L.listsize){		//当前存储空间已满，增加分配 
		int* newbase=(int*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase)return 0;		//分配空间失败，返回错误 
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	int* q=&(L.elem[i-1]);			//q为插入位置 
	for(int* p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;					//将插入位置之后的元素倒序依次后移 
	*q=e;							//插入e 
	++L.length;						//表长加1 
	return 1;
}

//删除线性表
int listDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)return 0;
	int *p=&(L.elem[i-1]);
	e=*p;
	int *q=L.elem+L.length-1;
	for(++p;p<=q;++p)*(p-1)=*p;
	--L.length;
	return 1;
} 

void print(SqList &L){ 
	for(int i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	printf("\n");
	return;
} 

//合并两个线性表
/*
已知顺序线性表La和Lb的元素按照值非递减排列
归并La和Lb得到的新的线性表Lc的元素也按照值非递减排列 

*/
int mergeSqList(SqList La,SqList Lb,SqList &Lc){
	int *pa=La.elem;
	int *pb=Lb.elem;
	Lc.listsize=Lc.length=La.length+Lb.length;
	int *pc=Lc.elem=(int*)malloc(Lc.listsize*sizeof(int*));
	if(!Lc.elem)return 0;			//存储空间分配失败 
	int *pa_last=La.elem+La.length-1;
	int *pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last){	//归并
		if(*pa<=*pb)*pc++=*pa++;			//La和Lb当前被指到的元素哪个小就先插哪个 
		else *pc++=*pb++; 
	}
	while(pa<=pa_last)*pc++=*pa++;		//插入La剩余元素 
	while(pb<=pb_last)*pc++=*pb++;		//插入Lb剩余元素 
	return 1;
} 
 

int main(){
	int i,e;
	SqList Sq,Sq2,Sq3;
	//建立线性表1 
	initSqList(Sq);	
	listInsert(Sq,1,2);
	listInsert(Sq,2,4);
	listInsert(Sq,3,6);
	printf("建表成功，表1中元素为:\n");
	print(Sq);
	printf("\n");
	//建立线性表2
	initSqList(Sq2);
	listInsert(Sq2,1,3);
	listInsert(Sq2,2,6);
	listInsert(Sq2,3,9);
	printf("建表成功，表2中元素为:\n");
	print(Sq2);
	mergeSqList(Sq,Sq2,Sq3);
	printf("插入后的新表为:\n");
	print(Sq3);
//	printf("请输入插入位置i和要插入的元素e:\n");
//	scanf("%d%d",&i,&e);
//	listInsert(Sq,i,e);	
//	printf("插入后的表为:\n");
//	print(Sq);
//	listDelete(Sq,i-1,e);
//	printf("请输入要删除的元素的位置i:\n");
//	scanf("%d",&i);
//	printf("删除后的表为:\n");
//	print(Sq);
//	printf("被删除的元素为%d",e); 
	return 0;
} 
