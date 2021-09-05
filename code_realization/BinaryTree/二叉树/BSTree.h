//刚学了一点模板的入门，暂时不能实战，后续补上先用C的风格写点最简单的
#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
} BSTNode, * BSTree;
void visit(BSTNode* node);
BSTNode* BST_Search(BSTree T, int key);        // 查找关键字 (非递归版本)
BSTNode* BST_SearchR(BSTree T, int key);       // 查找关键字 (递归版本)
bool BST_Insert(BSTree& T, int key);           // 二叉排序树插入操作
void BST_Create(BSTree& T, int* elems, int n); // 构造二叉排序树
