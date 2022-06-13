#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
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
void SelectSort(SqList &L)
{
	int i,k,j;
	RedType t;
	for(i=0;i<L.length-1;i++)
	{
		k=i;
		for(j=i+1;j<=L.length;j++)
			if(L.elem[j].key<L.elem[k].key) k=j;
		if(k!=i)
		{
			t=L.elem[i];
			L.elem[i]=L.elem[k];
			L.elem[k]=t;
		}
		printf("第%d趟排序后的结果:",i+1);
		PrintList(L); 
	}
 } 
int main()
{
	int i,a,n,e;
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
	SelectSort(L);
	return 0; 
}
