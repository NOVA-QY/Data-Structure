#include <stdio.h>  
#include <stdlib.h>  
#include <stdarg.h>  
#include <time.h>  
#define OK  1  
#define ERROR 0  
#define UNDERFLOW 2  
#define MAX_ARRAY_DIM 8  
typedef int Status;  
typedef int ElemType;  
typedef struct {  
    ElemType  *base;                //数组的实体  
    int       dim;                  //数组维数  
    int       *bounds;              //根据下文bound应该是bounds，数组各维的长度  
    int       *constants;           //数组映像函数常量的基址  
}Array;  
  
  
//数组初始化  
Status InitArray(Array *A, int dim,...)  
{  
  
    int elemtotal=1,i;   
    va_list ap;  
    if (dim < 1 || dim > MAX_ARRAY_DIM)   
            return ERROR;  
    A->dim = dim;  
    A->bounds = (int*)malloc(dim*sizeof(int));  
    if(!A->bounds)   
            return ERROR;  
    va_start(ap,dim);     
    for(i=0;i<dim;i++)  
    {  
        A->bounds[i] = va_arg(ap,int);  
        if(A->bounds[i]<0)   
                return UNDERFLOW;  
        elemtotal*=A->bounds[i];  
    }  
    va_end(ap);  
    A->base = (ElemType*)malloc(elemtotal*sizeof(ElemType));  
    if(!A->base)   
            return ERROR;  
    A->constants=(int*)malloc(dim*sizeof(int));  
    if(!A->constants)  
            return ERROR;  
    A->constants[dim-1] = 1;  
    for(i=dim-2;i>=0;--i)  
        A->constants[i]=A->bounds[i+1]*A->constants[i+1];  
    return OK;  
}  
  
  
//数组的销毁  
Status DestroyArray(Array *A)  
{     
    free(A->base);     
    free(A->bounds);  
    free(A->constants);  
    return OK;  
}  
  
  
//找到A的地址  
Status Locate(Array A,va_list ap,int *off)  
{  
    
    int ind, i;  
     
    *off=0;  
    for(i=0;i<A.dim;++i){  
        ind=va_arg(ap,int);  
        if(ind<0||ind>=A.bounds[i])  
                return ERROR;  
        *off+=A.constants[i]*ind;  
    }  
    return  OK;  
}  
  
//赋值把值赋值给数组A  
Status Assign(Array *A,ElemType e,...)  
{  
    va_list ap;  
    Status result;  
    int i,j,k;  
    int off;  
    va_start(ap,e);  
    if((result=Locate(*A,ap,&off))<0)  
            return result;  
    *(A->base+off)=e;  
    va_end(ap);  
    return OK;  
}  
  
//把值赋值给数组A中指定的元素e  
Status Value(Array A,ElemType *e,...)  
{  
    int off;  
    Status result;  
    va_list ap;  
    va_start(ap,e);  
    if ((result=Locate(A,ap,&off))<0)  
            return result;  
    *e=*(A.base+off);  
    va_start(ap,e);  
    return OK;  
}  
  
int main()  
{  
 int i,j,k;  
 Array A;  
 ElemType e;  
 A.dim=3;  
 InitArray(&A,A.dim,2,2,2);  
 printf("这是一个 %d 维的数组!\n",A.dim);  
 printf("数组每个维度的大小:\n");  
 for (i=0;i<A.dim;i++)   
         printf("第 %d 个维度大小为: %5d\n",i + 1, A.bounds[i]);  
 printf("函数常量的基址:\n");  
 for (i=0;i<A.dim;i++)   
         printf("第 %d 个基址 ： %5d\n",i + 1,A.constants[i]);  
 printf("\n输入任意值继续程序！\n");  
 getchar();  
 printf("随机生成一组数据:\n");  
 srand(time(0));  
 for (i=0;i<A.bounds[0];i++)  
   for (j=0;j<A.bounds[1];j++)  
      for(k=0;k<A.bounds[2];k++)  
        Assign(&A,rand()%100,i,j,k);  
 printf("数组A的成员是::\n");  
 for (i=0;i<A.bounds[0];i++)  
  {  
     for (j=0;j<A.bounds[1];j++)  
      {   
            printf("(");  
            for (k=0;k<A.bounds[2];k++)  
             {   
                     Value(A,&e,i,j,k);  
                    printf(" %5d ", e);  
            }  
             printf(")  ");  
        }  
            printf("\n");  
   }  
 printf("与之等效的一维数组是:\n");  
 for (i=0; i<A.bounds[0]*A.bounds[1]*A.bounds[2]; i++)   
         printf("%5d",A.base[i]);  
 printf("\n");  
 DestroyArray(&A);  
 getchar();  
 return 0;  
}  
