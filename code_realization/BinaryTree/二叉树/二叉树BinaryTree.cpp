#include <iostream>
#include<stdlib.h>
using namespace std;
//二叉树及头指针的定义
typedef struct BiTNode
{
	int data;//数据域
	struct BiTNode* lchild,*rchild;//指针域，此时还未typedef,同时初始化但每个都必须带星号
}BiTNode,* BiTree;
//二叉树的初始化函数
bool InitBiTree(BiTree & T, int data = 0)
{
	T = (BiTNode*)malloc(sizeof(BiTNode));
	if (T == NULL)
		return false;
	T->data = data;
	T->lchild = NULL;T->rchild = NULL;
	return true;
}
//新增节点
bool BiTreeIncrease(BiTNode* & N, int data = 0)
{
	N = (BiTNode*)malloc(sizeof(BiTNode));
	if (N == NULL)
		return false;
	N->data = data;
	N->lchild = NULL; N->rchild = NULL;
	return true;
}
//访问函数
void vist(BiTNode* T)
{
	cout << T->data << endl;
}
//中序遍历
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