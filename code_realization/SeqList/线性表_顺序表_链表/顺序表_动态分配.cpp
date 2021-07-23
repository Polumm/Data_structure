#pragma warning(disable:6386)//毙了 C6386：从..中写入到..时缓冲区溢出: 可写大小为..个字节，但可能写入了..个字节
#include <iostream>
#include <stdlib.h>//standard library malloc free
#define InitSize 10
using namespace std;
typedef struct
{
	int* data;//int指针
	int length;//当前长度
	int MaxSize;//最大长度
}SeqList;
void InitList(SeqList & L)
{
	L.data = (int*)malloc(InitSize * sizeof(int));
	cout << "请输入初始化元素：" << endl;
	if (L.data == NULL)//判空，不然报黄
	{
		cout << "初始化失败！" << endl;
		return;
	}
	for (int i = 0; i < InitSize; i++)
		cin >> L.data[i];
	L.length = InitSize;
	L.MaxSize = InitSize;
	cout << "初始化完成！" << endl;
}
void IncreaseSize(SeqList& L,int m)
{
	int* p = L.data;
	L.data = (int*)malloc((L.length + m) * sizeof(int));
	if (L.data == NULL)
	{
		cout << "初始化失败！" << endl;
		return;
	}
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	L.MaxSize = L.MaxSize + m;
	free(p);
	cout << "扩容完成！" << endl;
}
int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L, 3);
	cout << L.data[3];
}
