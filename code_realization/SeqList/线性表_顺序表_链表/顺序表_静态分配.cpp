//������int��ʵ�֣������滻��������elementType
#include <iostream>
#define InitSize 10//Ĭ�ϳ�ʼ������
#define MaxSize 20//��󳤶�
using namespace std;
typedef struct 
{
	int data[MaxSize];//��̬����
	int length;//��ǰ����
}SeqList;

void InitList(SeqList& L) //��ʼ������
{
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = InitSize;
}

bool ListInsert(SeqList& L, int n, int e)//���뺯��
{
	if (n<1 || n > L.length + 1)//����Ϸ����ж�
	{
		cout << "���벻�Ϸ���" << endl;
		return false;
	}
	if (L.length >= MaxSize)
	{
		cout << "����������" << endl;
		return false;
	}
	for (int i = L.length; i >= n; i--)//length��Ӧλ����������±�
	{
		L.data[i] = L.data[i-1];
	}
	L.data[n-1] = e;//ע��n��λ��n-1���������±�
	cout << "����ɹ�!" << endl;//shift  F9���ټ���
	L.length ++;
	return true;
}

bool ListDelete(SeqList& L, int n)//ɾ������
{
	if (n<1 || n > L.length+1)//����Ϸ����ж�
		return false;
	if (L.length == 0)
	{
		cout << "˳����ѿգ�" << endl;
		return false;
	}
	for (int i = n-1 ; i < L.length-1; i++)//length��Ӧλ����������±�
	{
		L.data[i] = L.data[i+1];
	}
	cout << "ɾ���ɹ�!" << endl;
	L.length--;
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
