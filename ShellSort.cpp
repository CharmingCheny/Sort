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
  RedType  *elem;     //ָ������Ԫ�صĻ���ַ
  int  length;       //���Ա�ĵ�ǰ����                                                           
}SqList;
int InitList(SqList &L)
{
	L.elem=new RedType[MAXSIZE]; //���ٴ洢�ռ� 
	if(!L.elem) exit(0);  //�洢ʧ���˳� 
	L.length=0;  //�ձ���Ϊ0 
	return OK;
 } 
int ListTailInsert(SqList &L,int i,int e)
{
	if((i<0)||(i>L.length)) return 0;  //�жϲ���λ���Ƿ�Ϸ� 
	if(L.length==MAXSIZE) return 0;  //�Ƿ񳤶ȳ�����󳤶� 
	L.elem[i].key=e;
	L.length++;  //���ȵ��� 
	return OK;
 }
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)//ѭ����ӡÿ��Ԫ�� 
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
 		printf("��%d�������Ľ��:",k+1);
 		PrintList(L);
	 }
 		
 }
 int main()
{
	int i,a,n,e,dt[9];
	SqList L;
	InitList(L);  //��ʼ�� 
	printf("���������Ԫ�ظ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++)  //β������ 
	{
		printf("���������Ԫ�أ�");
		scanf("%d",&e) ;
		ListTailInsert(L,i,e);
	}
	ShellSort(L,dt,3);
	return 0; 
}
