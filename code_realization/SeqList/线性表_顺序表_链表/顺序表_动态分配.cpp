#pragma warning(disable:6386)//���� C6386����..��д�뵽..ʱ���������: ��д��СΪ..���ֽڣ�������д����..���ֽ�
#include <iostream>
#include <stdlib.h>//standard library malloc free
#define InitSize 10
using namespace std;
typedef struct
{
	int* data;//intָ��
	int length;//��ǰ����
	int MaxSize;//��󳤶�
}SeqList;
void InitList(SeqList & L)
{
	L.data = (int*)malloc(InitSize * sizeof(int));
	cout << "�������ʼ��Ԫ�أ�" << endl;
	if (L.data == NULL)//�пգ���Ȼ����
	{
		cout << "��ʼ��ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < InitSize; i++)
		cin >> L.data[i];
	L.length = InitSize;
	L.MaxSize = InitSize;
	cout << "��ʼ����ɣ�" << endl;
}
void IncreaseSize(SeqList& L,int m)
{
	int* p = L.data;
	L.data = (int*)malloc((L.length + m) * sizeof(int));
	if (L.data == NULL)
	{
		cout << "��ʼ��ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	L.MaxSize = L.MaxSize + m;
	free(p);
	cout << "������ɣ�" << endl;
}
int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L, 3);
	cout << L.data[3];
}
