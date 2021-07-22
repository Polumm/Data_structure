#include <iostream>
#define InitSize 10//默认初始化长度
using namespace std;
//定义顺序表，顺序表里要有：数组指针、当前长度、最大长度
typedef struct {
	int data[InitSize];
	int length;//当前长度
	int MaxSize;//最大容量
}SeqList;
//初始化函数(数组名),静态数组初始化直接用循环，容量开好了
void InitList(SeqList& L) {
	for (int i = 0; i < InitSize; i++)
	{
		L.data[i] = 0;
	}
	L.length = InitSize;
}

int main()
{
	SeqList L;
	InitList(L);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << '\t';
	}
}