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
	int temp;//暂存待排元素
	for (int i = 1, j; i < len; i++) {//首元不用排
		temp = arr[i];
		for (j = i - 1; temp < arr[j] && j >= 0; j--) {
			if (temp < arr[j]) arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;//内层循环结束会--，这里得加回来
	}
}

