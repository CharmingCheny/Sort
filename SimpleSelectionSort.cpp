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
		printf("��%d�������Ľ��:",i+1);
		PrintList(L); 
	}
 } 
int main()
{
	int i,a,n,e;
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
	SelectSort(L);
	return 0; 
}
