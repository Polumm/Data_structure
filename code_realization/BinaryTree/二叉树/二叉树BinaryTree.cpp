#include <iostream>
#include<stdlib.h>
using namespace std;
//��������ͷָ��Ķ���
typedef struct BiTNode
{
	int data;//������
	struct BiTNode* lchild,*rchild;//ָ���򣬴�ʱ��δtypedef,ͬʱ��ʼ����ÿ����������Ǻ�
}BiTNode,* BiTree;
//�������ĳ�ʼ������
bool InitBiTree(BiTree & T, int data = 0)
{
	T = (BiTNode*)malloc(sizeof(BiTNode));
	if (T == NULL)
		return false;
	T->data = data;
	T->lchild = NULL;T->rchild = NULL;
	return true;
}
//�����ڵ�
bool BiTreeIncrease(BiTNode* & N, int data = 0)
{
	N = (BiTNode*)malloc(sizeof(BiTNode));
	if (N == NULL)
		return false;
	N->data = data;
	N->lchild = NULL; N->rchild = NULL;
	return true;
}
//���ʺ���
void vist(BiTNode* T)
{
	cout << T->data << endl;
}
//�������
void InOrder(BiTNode* T)
{
	if (T != NULL) 
	{
		InOrder(T->lchild);
		vist(T);
		InOrder(T->rchild);
	}
}
int main()
{
	BiTree root = NULL;
	InitBiTree(root);
	BiTreeIncrease(root->lchild, 99);
	BiTreeIncrease(root->rchild, 12);
	BiTreeIncrease(root->rchild->lchild, 15);
	BiTreeIncrease(root->rchild->rchild, 17);
	BiTreeIncrease(root->rchild->lchild->lchild, 13);
	InOrder(root);
}