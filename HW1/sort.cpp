#include "sort.h"
mysort::mysort(){
	count = 0;
}
mysort::~mysort(){		//소멸자
	delete[] arr;		//데이터 해제
}
void mysort::Qsort(int arr[], int a, int b){	//퀵 소트
	if (a >= b) return;				//a가 더 크면 진행하지 않는다.
	int l = a;						//왼쪽을 가리키는 것
	int r = b - 1;					//오른쪽을 가리키는 것
	int pivot = b;					//피벗은 맨 오른쪽
	while (l <= r){					//피벗 이동
		while (l<=r && arr[pivot] <= arr[r]){	//오른쪽에서 피벗보다 작은 값 발견 시
			--r;					//피벗 이동
		}
		while (l <= r && arr[pivot] >= arr[l]){	//왼쪽에서 비펏보다 큰 값 발견 시
			++l;					//피벗 이동
		}
		if (l<r)					//아직 오른쪽이 왼쪽보다 크다면 둘이 바꾼다.
			swap(arr[l], arr[r]);
	}
		swap(arr[l], arr[pivot]);	//왼쪽이 오른쪽보다 크다면 피벗과 왼쪽을 바꾼다.
		Qsort(arr,a,l-1);			//앞쪽 퀵 소트
		Qsort(arr,l+1,pivot);		//뒤쪽 퀵 소트
}
void mysort::MedianQsort(int arr[], int a, int b){		//Median-of-three Quick Sort
	if (a >= b) return;				//a가 더 크면 진행하지 않는다.
	int l = a;						//왼쪽을 가리키는 것
	int r = b - 1;					//오른쪽을 가리키는 것
	int pivot = b;					//피벗은 맨 오른쪽

	if (b - a >= 2){					//데이터의 개수가 충분히 있다면
		int x[3] = { b, b-1, b-2};	//3개의 값
		sort(x, x + 3);				//가운데값 찾기 위해 정렬
		swap(arr[x[1]], arr[pivot]);//가운데값과 피벗과 스왑
	}

	while (l <= r){					//피벗 이동
		while (l <= r && arr[pivot] <= arr[r]){	//오른쪽에서 피벗보다 작은 값 발견 시
			--r;					//피벗 이동
		}
		while (l <= r && arr[pivot] >= arr[l]){	//왼쪽에서 비펏보다 큰 값 발견 시
			++l;					//피벗 이동
		}
		if (l<r)					//아직 오른쪽이 왼쪽보다 크다면 둘이 바꾼다.
			swap(arr[l], arr[r]);
	}
	swap(arr[l], arr[pivot]);	//왼쪽이 오른쪽보다 크다면 피벗과 왼쪽을 바꾼다.
	Qsort(arr, a, l - 1);			//앞쪽 퀵 소트
	Qsort(arr, l + 1, pivot);		//뒤쪽 퀵 소트
}
void mysort::insert(int num){		//데이터 입력
	arr[count] = num;				//데이터 입력
	count++;						//입력된 데이터 개수 증가
}
