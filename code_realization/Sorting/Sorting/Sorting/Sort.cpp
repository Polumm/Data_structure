#include <iostream>
#include "SortingMethods.h"
using namespace std;
int main() {
	int len = 12;
	int arr[] = { 9,7,5,3,2,4,6,8,1,-9,55,-102};
	InsertionSort(arr, len);
	for (int i = 0; i < len; i++){
		cout << arr[i] << endl;
	}
}
void InsertionSort(int arr[], int len) {
	int temp;//�ݴ����Ԫ��
	for (int i = 1, j; i < len; i++) {//��Ԫ������
		temp = arr[i];
		for (j = i - 1; temp < arr[j] && j >= 0; j--) {
			if (temp < arr[j]) arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;//�ڲ�ѭ��������--������üӻ���
	}
}

