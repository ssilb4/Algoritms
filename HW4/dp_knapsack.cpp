#include "dp_knapsack.h"

dp_knap::dp_knap() {							//생성자
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 1001; j++) {
			p[i][j] = -1;						//-1로 초기화한다. 계산을 하지 않았다는 의미이다.
		}
	}
}

int dp_knap::dp(int pt[], int w[], int n, int W) {		//dp를 이용한 접근
														/*
														단순한 동적 계획법일 때의 알고리즘
														for (int i = 1; i <= n; i++) {
														for (int j = 0; j <= W; j++) {
														if (j >= w[i])
														p[i][j] = max(p[i - 1][j], pt[i] + p[i - 1][j - w[i]]);
														else
														p[i][j] = p[i - 1][j];
														}
														}

														*/
	if (p[n][W] != -1) return p[n][W];				//이전에 저장이 되었다면 그 값을 리턴
	if (n > 0) {									//n이 0보다 클 때는 계산이 필요하다.
		if (W >= w[n]) {							//담을 수 있는 경우
			if (p[n - 1][W] == -1) {				//p[n-1][W] 값이 저장되어 있지 않다면
				p[n - 1][W] = dp(pt, w, n - 1, W);	//재귀 호출을 해서 저장
			}
			if (p[n - 1][W - w[n]] == -1) {			//p[n - 1][W - w[n]] 값이 저장되어 있지 않다면
				p[n - 1][W - w[n]] = dp(pt, w, n - 1, W - w[n]);	//재귀 호출을 해서 저장
			}
			p[n][W] = max(p[n - 1][W], p[n - 1][W - w[n]] + pt[n]);	//p[n][W] 값 저장
			print_graph(3, 30);					//애니메이션을 위한 호출
			return p[n][W];							//배낭채우기에서 p[i][W] 를 구하는 방식인데 그 때 리턴하기 전에 미리 값을 저장한다.
		}
		else {										//담을 수 없는 경우
			if (p[n - 1][W] == -1) {					//p[n-1][W] 값이 저장되어 있지 않다면
				p[n - 1][W] = dp(pt, w, n - 1, W);		//그 전 값을 저장
			}
			return p[n - 1][W];						//그 전 값을 리턴
		}
	}
	else {
		p[n][W] = 0;							//n이 0일 경우 p[n][W] 를 0으로 저장
		print_graph(3, 30);						//애니메이션을 위한 호출
		return p[n][W];							//p[n][W] 를 리턴
	}
}

void dp_knap::print_graph(int n, int W) {			//그래프 출력
	system("cls");								//애니메이션을 위한 호출(창 지우기)
	for (int i = -1; i <= n; i++) {
		if (i == -1) cout << " ";					//i=0 이면 공백만 출력(줄맞추기)
		else cout << i;								//그 외에는 i 출력(행 숫자)
		for (int j = 0; j <= W; j++) {
			if (i == -1) cout << setw(4) << j;		//i=0 이면 j 출력(줄 맞추기)
			else cout << setw(4) << p[i][j];		//그 외에는 p[i][j] 출력 (열 맞추기)
		}
		cout << endl;
	}
	Sleep(1000);								//애니메이션을 위한 호출 (잠시 멈춤)
}

//애니메이션용 DPcpp