#include <iostream>
using namespace std;
typedef struct LNode
{
	int data;
	LNode* next;
}LNode, * LinkList;
bool InitList(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		cout << "ÉêÇëÊ§°Ü£¡" << endl;
		return false;
	}
	L->next = NULL;
}
bool Empty(LinkList& L)
{
	return(L->next == NULL);
}
int main()	
{
	LinkList L;
	InitList(L);
	cout << Empty(L) << endl;
}