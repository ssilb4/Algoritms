#ifndef AARR_H
#define AARR_H
#include "node.h"
class Aarr {			//A관련 클래스
public:
	Aarr();				//생성자
	double A[max_size][max_size];		//A행렬
	double OptimalBST(double p[], int r[][max_size], int n);	//최적이진탐색트리 알고리즘
	void print_A(int size);				//A행렬 출력
};
#endif AARR_H