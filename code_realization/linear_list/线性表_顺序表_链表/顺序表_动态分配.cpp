#include <iostream>
#include <stdlib.h>
using namespace std;
#define InitSize 10//Ĭ�ϳ�ʼ������Ϊ10
//SqList�ṹ�嶨�壬����������ָ�롢��ǰ���ȡ���󳤶�

typedef struct {
	int* data;
	int length;//��ǰ����
	int MaxSize;//��󳤶�
}SqList;

//��ʼ������
void InitList(SqList & L){
	L.data = (int*)malloc(InitSize * sizeof(int));
	cout << "�������룺" << endl;
	if (L.data == NULL) {
		cout << "�ռ�����ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < InitSize; i++) {
		cin >> L.data[i];
	}
	cout << "OK!" << endl;
	L.MaxSize = InitSize;
	L.length = InitSize;
}
//���ݺ���,�����������С
void IncreaseSize(SqList& L,int m) {
	int* p = L.data;//pָ��ָ��data����
	L.data = (int*)malloc((L.MaxSize + m )* sizeof(int));//dataָ����һƬȫ�¿ռ�
	if (p == NULL) {
		cout << "�ռ�����ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < L.length; i++) {//����Ǩ��
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + m;
	free(p);
}
int main() {
	SqList L;
	InitList(L);
	IncreaseSize(L, 4);
	cout << "a";
}