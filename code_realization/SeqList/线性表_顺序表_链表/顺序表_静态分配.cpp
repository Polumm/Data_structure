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
//��ʼ������(������),��̬�����ʼ��ֱ����ѭ��������������
void InitList(SeqList& L) 
{
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = InitSize;
}
bool InsertList(SeqList& L, int n, int e)//λ��Ԫ��
{
	if (n<1 || n > L.length + 1)//����Ϸ����ж�
		return false;
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

int main()
{
	SeqList L;
	InitList(L);
	InsertList(L, 3, 99);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
}
