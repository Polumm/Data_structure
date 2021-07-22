#include <iostream>
#include <stdlib.h>
using namespace std;
#define InitSize 10//默认初始化长度为10
//SqList结构体定义，包含：数组指针、当前长度、最大长度

typedef struct {
	int* data;
	int length;//当前长度
	int MaxSize;//最大长度
}SqList;

//初始化函数
void InitList(SqList & L){
	L.data = (int*)malloc(InitSize * sizeof(int));
	cout << "请您输入：" << endl;
	if (L.data == NULL) {
		cout << "空间申请失败！" << endl;
		return;
	}
	for (int i = 0; i < InitSize; i++) {
		cin >> L.data[i];
	}
	cout << "OK!" << endl;
	L.MaxSize = InitSize;
	L.length = InitSize;
}
//拓容函数,表名，扩充大小
void IncreaseSize(SqList& L,int m) {
	int* p = L.data;//p指针指向data数组
	L.data = (int*)malloc((L.MaxSize + m )* sizeof(int));//data指向另一片全新空间
	if (p == NULL) {
		cout << "空间申请失败！" << endl;
		return;
	}
	for (int i = 0; i < L.length; i++) {//数据迁移
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + m;
	free(p);
}
int main() {
	SqList L;
	InitList(L);
	IncreaseSize(L, 4);
	cout << "a";
}