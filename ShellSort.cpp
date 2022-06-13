#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef struct
{
	int key;
}RedType;
typedef struct
{
  RedType  *elem;     //指向数据元素的基地址
  int  length;       //线性表的当前长度                                                           
}SqList;
int InitList(SqList &L)
{
	L.elem=new RedType[MAXSIZE]; //开辟存储空间 
	if(!L.elem) exit(0);  //存储失败退出 
	L.length=0;  //空表长度为0 
	return OK;
 } 
int ListTailInsert(SqList &L,int i,int e)
{
	if((i<0)||(i>L.length)) return 0;  //判断插入位置是否合法 
	if(L.length==MAXSIZE) return 0;  //是否长度超过最大长度 
	L.elem[i].key=e;
	L.length++;  //长度递增 
	return OK;
 }
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)//循环打印每个元素 
	{
		printf("%d\t",L.elem[i].key);
	}
	printf("\n");
 } 
 void ShellInsert(SqList &L,int dk)
 {
 	int i,j;
 	RedType T;
 	for(i=dk+1;i<=L.length;i++)
 		if(L.elem[i-1].key<L.elem[i-dk-1].key)
 		{
 			T=L.elem[i-1];
 			for(j=i-dk;j>0&&T.key<L.elem[j-1].key;j-=dk)
 				L.elem[j+dk-1]=L.elem[j-1];
 			L.elem[j+dk-1]=T;
		 }
 }
 void ShellSort(SqList &L, int dt[], int t)
 {
 	for(int k=0;k<t;k++)
 	{
 		ShellInsert(L,dt[k]);
 		printf("第%d趟排序后的结果:",k+1);
 		PrintList(L);
	 }
 		
 }
 int main()
{
	int i,a,n,e,dt[9];
	SqList L;
	InitList(L);  //初始化 
	printf("请输入插入元素个数：");
	scanf("%d",&n);
	for(i=0;i<n;i++)  //尾部插入 
	{
		printf("请输入插入元素：");
		scanf("%d",&e) ;
		ListTailInsert(L,i,e);
	}
	ShellSort(L,dt,3);
	return 0; 
}
