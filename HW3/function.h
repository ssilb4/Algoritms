#ifndef FUNCTION_H
#define FUNCTION_H
#define inf 10000
#include <iostream>
#include <iomanip>
using namespace std;

void floyd(int n,int temp[][100], int p[][100]);					//�÷��̵�
void tsp(int n, int W[][100], int p[][100], int& minlength);		//tsp
int bitcnt(int n);													//tsp ���� �ʿ��� ��Ʈ���� ���� �Լ�


#endif