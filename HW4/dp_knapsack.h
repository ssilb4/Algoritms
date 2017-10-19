#ifndef DP_KNAPSACK_H
#define DP_KNAPSACK_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <windows.h>
using namespace std;

class dp_knap {									//dp로 하는 knapsack
private:
	int p[11][1001];							//dp 저장
public:
	dp_knap();									//생성자
	int dp(int pt[], int w[], int n, int W);	//knapsack 실행
	void print_graph(int n, int W);				//graph 출력
};

#endif