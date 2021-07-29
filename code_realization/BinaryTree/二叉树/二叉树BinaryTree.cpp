#include <iostream>
#include<stdlib.h>
using namespace std;
//��������ͷָ��Ķ���
typedef struct BiTNode
{
	int data;//������
	struct BiTNode* lchild,*rchild;//ָ���򣬴�ʱ��δtypedef,ͬʱ��ʼ��ÿ����������Ǻ�!
	int ltag, rtag;//������ʶ��0��ʾ���ӵ������Һ��ӣ�1��ʾ���ӵ���ǰ����̽��
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
//����ʱ���ʱ��������ʶ
void vistTread(BiTNode* T, BiTree& pre)
{
	if (T != NULL)//ʵ�ֶ�����һ��ҪС�ģ��������������������
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
		pre = T;//ע��pre�����λ��
	}
}
//�������ı���
void InTread(BiTree & T, BiTree& pre)
{
	if (T != NULL)
	{
		InTread(T->lchild,pre);
		vistTread(T,pre);
		InTread(T->rchild,pre);
	}
}
//��������
void makeTread(BiTree& T)
{
	BiTNode* pre = NULL;//����������ʱ�õ���ָ��
	if (T != NULL)
		InTread(T, pre);
	if (pre != NULL)
	{
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
//�ҵ��Ե�ǰ�ڵ�Ϊ���������У���һ������������Ľ��
BiTNode* Firstnode(BiTNode* p)
{
	if (p != NULL)
	{
		while (p->ltag == 0)	p = p->lchild;//һֱ�������е�����
		return p;
	}
}
//������������ҵ�p�ĺ�̽ڵ�
BiTNode* Nextnode(BiTNode* p)
{
	if (p->rtag == 0)	return Firstnode(p->rchild);
	else return p->rchild;//rtag==1ֱ�ӷ���
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
	makeTread(root);//������ʵ�ֵķǵݹ�����㷨
	TreadInOrder(root);
}