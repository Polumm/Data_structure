#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	LNode* next;
} LNode, * LinkList;
bool InitList(LinkList & L)
{
	L = NULL;
	return true;
}
bool Empty(LinkList & L)
{
	return(L == NULL);
}
int main()
{
	LinkList L;
	InitList(L);
	cout << Empty(L);
}