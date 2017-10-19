#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
using namespace std;
class mysort{
private:
	int count;		//입력된 데이터 개수
public:
	mysort();		//생성자
	~mysort();		//소멸자
	void Qsort(int arr[],int a, int b);		//기본 Quick Sort
	void insert(int num);					//데이터 삽입
	void MedianQsort(int arr[], int a, int b); //Median-of-three Quick Sort
	int* arr;		//데이터 저장하는 곳
};
#endif
