#include "rarr.h"	//r 행렬 관련
#include "Aarr.h"	//A 행렬 관련
int main() {
	Aarr myA[5];	// A행렬 관련 클래스
	rarr myr[5];	// r행렬 관련 클래스
	int size;		// 행렬 크기
	double p[max_size] = { 0, };	//각 노드의 확률
	for (int i = 0; i < 5; i++) {		// 5개의 예
		cout << "노드의 개수 입력(26이하): ";
		cin >> size;					//노드 개수 입력
		cout << endl;
		cout << "인덱스의 확률을 순서대로 입력" << endl;
		for (int j = 1; j <= size; j++) {
			cin >> p[j];								//노드별 확률 입력
		}
		cout << endl;
		myA[i].OptimalBST(p, myr[i].r, size);			//최적 이진 탐색 트리 알고리즘
		myA[i].print_A(size);							//A 행렬 출력
		myr[i].print_r(size);							//r 행렬 출력
		myr[i].print_tree(myr[i].BuildTree(1, size),1);	//최적 이진 탐색 트리 출력
	}
	return 0;
}