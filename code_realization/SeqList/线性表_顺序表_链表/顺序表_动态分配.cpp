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

void InitList(SeqList & L)//��ʼ������
{
	L.MaxSize = 20;
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
	cout << "��ʼ����ɣ�" << endl;
}

void IncreaseSize(SeqList& L,int m)//���ݺ���
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
bool ListInsert(SeqList& L, int n, int e)//���뺯��
{
	if (n<1 || n > L.length + 1)//����Ϸ����ж�
	{
		cout << "���벻�Ϸ���" << endl;
		return false;
	}
	if (L.length >= L.MaxSize)
	{
		cout << "����������" << endl;
		return false;
	}
	for (int i = L.length; i >= n; i--)//length��Ӧλ����������±�
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[n - 1] = e;//ע��n��λ��n-1���������±�
	cout << "����ɹ�!" << endl;//shift  F9���ټ���
	L.length++;
	return true;
}

bool ListDelete(SeqList& L, int n)//ɾ������
{
	if (n<1 || n > L.length + 1)
	{
		cout << "���벻�Ϸ���" << endl;
		return false;
	}
	if (L.length == 0) 
	{
		cout << "˳����ѿգ�" << endl;
		return false;
	}
	for (int i = n - 1; i < L.length-1; i++)
	{
		L.data[i] = L.data[i + 1];
	}
	L.length--;
	cout << "ɾ���ɹ�!" << endl;
	return true;
}

int main()
{
	SeqList L;
	InitList(L);
	ListInsert(L, 3, 99);//��֤����
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
	cout << endl;
	ListDelete(L, 3);//��֤ɾ��
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
}
