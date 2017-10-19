#ifndef GA_KNAPSACK_H
#define HA_KNAPSACk_H

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ctime>        //������ ������ ���ؼ�
#include <stdlib.h>    //���� �Լ� ���� ���ؼ�
#include "gene.h"
#include <Windows.h>
using namespace std;

#define number 30			//������ ����


class ga_knap {									//GA�� �̿��� kanapsack
private:
	_gene gene[100];							//������
	int size;									//ũ��
	int generation;
public:
	ga_knap();									//����Ʈ ������
	ga_knap(int n);								//�������� ���̰� n
	int random();								//������ ����� �Լ�
	void fit(int p[], int w[], int W);			//fitness ����Լ�
	void select();								//selection �Լ�
	void crossover();							//crossover(����) �Լ�
	void mutation();							//mutation(��������) �Լ�
	void scaling();								//scaling �Լ�
	void print_result(int p[]);					//��� ��� �Լ�
	void print_gene();
};



#endif