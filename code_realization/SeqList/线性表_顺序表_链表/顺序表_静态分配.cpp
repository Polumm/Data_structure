#include <iostream>
#define InitSize 10//Ĭ�ϳ�ʼ������
using namespace std;
typedef struct 
{
	int data[InitSize];//��̬����
	int length;//��ǰ����
	int MaxSize;//�������
}SeqList;
//��ʼ������(������),��̬�����ʼ��ֱ����ѭ��������������
void InitList(SeqList& L) 
{
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = InitSize;
	L.MaxSize = InitSize;
}

int main()
{
	SeqList L;
	InitList(L);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
}