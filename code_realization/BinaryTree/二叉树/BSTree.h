//��ѧ��һ��ģ������ţ���ʱ����ʵս��������������C�ķ��д����򵥵�
#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
} BSTNode, * BSTree;
void visit(BSTNode* node);
BSTNode* BST_Search(BSTree T, int key);        // ���ҹؼ��� (�ǵݹ�汾)
BSTNode* BST_SearchR(BSTree T, int key);       // ���ҹؼ��� (�ݹ�汾)
bool BST_Insert(BSTree& T, int key);           // �����������������
void BST_Create(BSTree& T, int* elems, int n); // �������������
