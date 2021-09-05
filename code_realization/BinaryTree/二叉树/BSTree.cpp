#include"BSTree.h"
//访问
void visit(BSTNode* N) {
    if (N) cout << N->data << ' ';
    else cout << "NULL" << ' ';
}
//BSTree的插入
bool BST_Insert(BSTree& T, int key) {//不如把第一个参数当作是是(当前)搜索指针
    if (T == NULL) {                                     // 所有新插入的结点都是叶子节点，即当前指针为空
        T = (BSTNode*)malloc(sizeof(BSTNode));
        T->data = key;
        T->rchild = T->lchild = NULL;//显然lchild是指针
        return true;
    }
    //接下来比较当前结点数据域和搜索值之间的大小
    else if (key == T->data) {                           // 树中存在相同关键字的结点，插入失败
        return false;
    }
    else if (key < T->data) {                            // 搜索指针左移
        return BST_Insert(T->lchild, key);
    }
    else {                                            // 搜索指针右移
        return BST_Insert(T->rchild, key);
    }
}
//BSTree的初始化即为一个个的插入，循环调用插入函数
void BST_Create(BSTree& T, int elems[], int n) {//根节点、插入元素表、插入元素个数
    for (int i = 0; i < n; i++)
        BST_Insert(T, elems[i]);
}
//递归搜索
BSTNode* BST_SearchR(BSTree T, int key) {//T实际是头指针
    if (!T) return T;//空指针，查找结束
    else if (T->data == key) return T;
    else if (T->data < key) BST_SearchR(T->rchild, key);
    else BST_SearchR(T->lchild, key);
}
//非递归搜索
BSTNode* BST_Search(BSTree T, int key) {//思路是循环内修改搜索指针
    while (T){
        if (T->data == key) return T;
        else if (T->data < key) T = T->rchild;
        else T = T->lchild;
    }
    return T;
}


