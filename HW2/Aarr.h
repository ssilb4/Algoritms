#ifndef AARR_H
#define AARR_H
#include "node.h"
class Aarr {			//A���� Ŭ����
public:
	Aarr();				//������
	double A[max_size][max_size];		//A���
	double OptimalBST(double p[], int r[][max_size], int n);	//��������Ž��Ʈ�� �˰���
	void print_A(int size);				//A��� ���
};
#endif AARR_H