#include"BSTree.h"
//����
void visit(BSTNode* N) {
    if (N) cout << N->data << ' ';
    else cout << "NULL" << ' ';
}
//BSTree�Ĳ���
bool BST_Insert(BSTree& T, int key) {//����ѵ�һ��������������(��ǰ)����ָ��
    if (T == NULL) {                                     // �����²���Ľ�㶼��Ҷ�ӽڵ㣬����ǰָ��Ϊ��
        T = (BSTNode*)malloc(sizeof(BSTNode));
        T->data = key;
        T->rchild = T->lchild = NULL;//��Ȼlchild��ָ��
        return true;
    }
    //�������Ƚϵ�ǰ��������������ֵ֮��Ĵ�С
    else if (key == T->data) {                           // ���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
        return false;
    }
    else if (key < T->data) {                            // ����ָ������
        return BST_Insert(T->lchild, key);
    }
    else {                                            // ����ָ������
        return BST_Insert(T->rchild, key);
    }
}
//BSTree�ĳ�ʼ����Ϊһ�����Ĳ��룬ѭ�����ò��뺯��
void BST_Create(BSTree& T, int elems[], int n) {//���ڵ㡢����Ԫ�ر�����Ԫ�ظ���
    for (int i = 0; i < n; i++)
        BST_Insert(T, elems[i]);
}
//�ݹ�����
BSTNode* BST_SearchR(BSTree T, int key) {//Tʵ����ͷָ��
    if (!T) return T;//��ָ�룬���ҽ���
    else if (T->data == key) return T;
    else if (T->data < key) BST_SearchR(T->rchild, key);
    else BST_SearchR(T->lchild, key);
}
//�ǵݹ�����
BSTNode* BST_Search(BSTree T, int key) {//˼·��ѭ�����޸�����ָ��
    while (T){
        if (T->data == key) return T;
        else if (T->data < key) T = T->rchild;
        else T = T->lchild;
    }
    return T;
}


