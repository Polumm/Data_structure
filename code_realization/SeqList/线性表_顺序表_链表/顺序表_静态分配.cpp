#include <iostream>
#define InitSize 10//默认初始化长度
using namespace std;
typedef struct 
{
	int data[InitSize];//静态数组
	int length;//当前长度
	int MaxSize;//最大容量
}SeqList;
//初始化函数(数组名),静态数组初始化直接用循环，容量开好了
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