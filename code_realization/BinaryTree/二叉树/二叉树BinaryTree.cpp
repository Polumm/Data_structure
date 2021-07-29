#include <iostream>
#include<stdlib.h>
using namespace std;
//二叉树及头指针的定义
typedef struct BiTNode
{
	int data;//数据域
	struct BiTNode* lchild,*rchild;//指针域，此时还未typedef,同时初始化每个都必须带星号!
	int ltag, rtag;//线索标识：0表示连接的是左右孩子，1表示连接的是前驱后继结点
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
//访问时结点时线索化标识
void vistTread(BiTNode* T, BiTree& pre)
{
	if (T != NULL)//实现二叉树一定要小心，经常会遇到空树的情况
	{
		if (T->lchild == NULL)
		{
			T->lchild = pre;
			T->ltag = 1;
		}
		else
			T->ltag = 0;
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = T;
			pre->rtag = 1;
		}
		else if(pre != NULL)
			pre->rtag = 0;
		pre = T;//注意pre这里的位置
	}
}
//线索化的遍历
void InTread(BiTree & T, BiTree& pre)
{
	if (T != NULL)
	{
		InTread(T->lchild,pre);
		vistTread(T,pre);
		InTread(T->rchild,pre);
	}
}
//创建线索
void makeTread(BiTree& T)
{
	BiTNode* pre = NULL;//定义线索化时用到的指针
	if (T != NULL)
		InTread(T, pre);
	if (pre != NULL)
	{
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
//找到以当前节点为根的子树中，第一个被中序遍历的结点
BiTNode* Firstnode(BiTNode* p)
{
	if (p != NULL)
	{
		while (p->ltag == 0)	p = p->lchild;//一直找子树中的左孩子
		return p;
	}
}
//在中序遍历中找到p的后继节点
BiTNode* Nextnode(BiTNode* p)
{
	if (p->rtag == 0)	return Firstnode(p->rchild);
	else return p->rchild;//rtag==1直接返回
}
void TreadInOrder(BiTNode* T)
{
	for (BiTNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
		vist(p);
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
	cout << "//===========================" << endl;
	makeTread(root);//线索化实现的非递归遍历算法
	TreadInOrder(root);
}