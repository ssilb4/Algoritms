#ifndef DP_KNAPSACK_H
#define DP_KNAPSACK_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <windows.h>
using namespace std;

class dp_knap {									//dp�� �ϴ� knapsack
private:
	int p[11][1001];							//dp ����
public:
	dp_knap();									//������
	int dp(int pt[], int w[], int n, int W);	//knapsack ����
	void print_graph(int n, int W);				//graph ���
};

#endif