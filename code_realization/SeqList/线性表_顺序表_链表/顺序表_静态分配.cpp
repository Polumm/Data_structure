//这里用int型实现，可以替换成其他的elementType
#include <iostream>
#define InitSize 10//默认初始化长度
#define MaxSize 20//最大长度
using namespace std;
typedef struct 
{
	int data[MaxSize];//静态数组
	int length;//当前长度
}SeqList;

void InitList(SeqList& L) //初始化函数
{
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = InitSize;
}

bool ListInsert(SeqList& L, int n, int e)//插入函数
{
	if (n<1 || n > L.length + 1)//输入合法性判断
	{
		cout << "输入不合法！" << endl;
		return false;
	}
	if (L.length >= MaxSize)
	{
		cout << "容量已满！" << endl;
		return false;
	}
	for (int i = L.length; i >= n; i--)//length对应位序而非数组下标
	{
		L.data[i] = L.data[i-1];
	}
	L.data[n-1] = e;//注意n是位序，n-1才是数组下标
	cout << "插入成功!" << endl;//shift  F9快速监视
	L.length ++;
	return true;
}

bool ListDelete(SeqList& L, int n)//删除函数
{
	if (n<1 || n > L.length+1)//输入合法性判断
		return false;
	if (L.length == 0)
	{
		cout << "顺序表已空！" << endl;
		return false;
	}
	for (int i = n-1 ; i < L.length-1; i++)//length对应位序而非数组下标
	{
		L.data[i] = L.data[i+1];
	}
	cout << "删除成功!" << endl;
	L.length--;
	return true;
}

int main()
{
	SeqList L;
	InitList(L);
	ListInsert(L, 3, 99);//验证插入
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
	cout << endl;
	ListDelete(L, 3);//验证删除
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
}
