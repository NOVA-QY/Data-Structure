/*
	存疑 
*/ 

#include<cstdio>
#include<iostream>
#include<cstdlib> 
using namespace std;

typedef struct{
	char *ch;
	int length;
}HString;


//为串分配空间、赋值
int StrAssign(HString &T,char *chars){
	int i;
//	if(T.ch)free(T.ch);					//释放T原有空间 【1】 
	char *c=chars;
	for(i=0;*c!='\0';++i,++c);		//求chars的长度i
	if(!i){
		T.ch=NULL;
		T.length=0;
	}else{
		if(!(T.ch=(char*)malloc(i*sizeof(char))))return 0;	//分配空间的同时判断是否成功分配 
		for(int j=0;j<i;j++)
			T.ch[j]=chars[j];
		T.length=i;
	}
	
	return 1;
}


//求长度
int StrLength(HString S){
	return S.length;
} 


//字符串比较
int StrCompare(HString S,HString T){
	//规则:若S>T,则返回值>0，若S=T，则返回值=0,若S<T，则返回值<0
	for(int i=0;i<S.length&&i<T.length;++i)
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i]; 
	return S.length-T.length;
} 


int ClearString(HString &S){
	//将S清为空串
	if(S.ch){
		free(S.ch);
		S.ch=NULL;
	} 
	S.length=0;
	return 1;
}

int SubString(HString &Sub,HString S,int pos,int len){
	//用Sub返回串S的第pos个字符起长度为len的子串 
	//1<=pos<=StrLength(S)且0<=len<=StrLength(S)-pos+1 

	if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
		return 0;
			
//	if(Sub.ch)free(Sub.ch);			//【2】 
	if(!len){
		Sub.ch=NULL;
		Sub.length=0;
	}else{
		Sub.ch=(char*)malloc(len*sizeof(char));
		for(int i=0;i<len;i++)
			Sub.ch[i]=S.ch[pos-1+i];
		Sub.length=len;
	}
	return 1;
}

int Concat(HString &T,HString S1,HString S2){
	//用T返回由S1和S2连接而成的新串ksckslm
//	if(T.ch)free(T.ch);

	T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char));
//	if(!()); 
//		return 0;
	for(int i=0;i<S1.length;i++){ 

		T.ch[i]=S1.ch[i];
	} 
	T.length=S1.length+S2.length;
	for(int i=0;i<S2.length;i++){
		T.ch[S1.length+i]=S2.ch[i];
	}
	return 1;
}


int main(){
	int res;
	HString str1,str2,str3,str4;
	int start,end;
	char s1[100];
	char s2[100];
	
	scanf("%s%s",s1,s2);
	StrAssign(str1,s1);
	StrAssign(str2,s2);
	//测试赋值函数 
	printf("输入的两个字符串分别为:\n");
	printf("%s\n",str1.ch);
	printf("%s\n",str2.ch);
	
	//测试字符串比较方法 
	printf("比较的结果为:\n");
	res=StrCompare(str1,str2);
	printf("%d\n",res); 
	
	//测试求子串方法 
	printf("请输入子串的起止位置:\n");
	scanf("%d%d",&start,&end);
	printf("原串中位置从%d到%d的子串为:\n",start,end);
	SubString(str3,str1,start,end);
	printf("%s\n",str3.ch);

	//测试字符串联接方法 
	printf("联接的结果为:\n"); 
	Concat(str4,str1,str2);

	printf("%s",str4.ch);
	
//	ClearString(str);
//	printf("清空后:\n"); 
//	printf("%s\n",str.ch);
	return 0;
}
