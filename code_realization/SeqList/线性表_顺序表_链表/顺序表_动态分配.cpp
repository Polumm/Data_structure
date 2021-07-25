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

void InitList(SeqList & L)//初始化函数
{
	L.MaxSize = 20;
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
	cout << "初始化完成！" << endl;
}

void IncreaseSize(SeqList& L,int m)//拓容函数
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
bool ListInsert(SeqList& L, int n, int e)//插入函数
{
	if (n<1 || n > L.length + 1)//输入合法性判断
	{
		cout << "输入不合法！" << endl;
		return false;
	}
	if (L.length >= L.MaxSize)
	{
		cout << "容量已满！" << endl;
		return false;
	}
	for (int i = L.length; i >= n; i--)//length对应位序而非数组下标
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[n - 1] = e;//注意n是位序，n-1才是数组下标
	cout << "插入成功!" << endl;//shift  F9快速监视
	L.length++;
	return true;
}

bool ListDelete(SeqList& L, int n)//删除函数
{
	if (n<1 || n > L.length + 1)
	{
		cout << "输入不合法！" << endl;
		return false;
	}
	if (L.length == 0) 
	{
		cout << "顺序表已空！" << endl;
		return false;
	}
	for (int i = n - 1; i < L.length-1; i++)
	{
		L.data[i] = L.data[i + 1];
	}
	L.length--;
	cout << "删除成功!" << endl;
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
