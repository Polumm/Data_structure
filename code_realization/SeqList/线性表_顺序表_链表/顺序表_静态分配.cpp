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
//初始化函数(数组名),静态数组初始化直接用循环，容量开好了
void InitList(SeqList& L) 
{
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = InitSize;
}
bool InsertList(SeqList& L, int n, int e)//位序、元素
{
	if (n<1 || n > L.length + 1)//输入合法性判断
		return false;
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

int main()
{
	SeqList L;
	InitList(L);
	InsertList(L, 3, 99);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
}
