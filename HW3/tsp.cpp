#include "function.h"
#include <math.h> 
int bitcnt(int n) {//브라이언 커니건의 비트 카운트
	int c, v = n;
	for (c = 0; v; c++)
	{
		v &= v - 1; // clear the least significant bit set
	}
	return c;														//비트 개수 리턴
}

void tsp(int n, int W[][100], int p[][100], int& minlength) {		//tsp 알고리즘
	int D[100][100];												//중간 경로들 행렬
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			D[i][j] = inf;											//inf를 초기화
		}
	}
	int set;														//집합을 나타내는 set (비트가 1이면 집합의 원소)
	for (int i = 2; i <= n; i++) {
		D[i][0] = W[i][1];											//하나도 안 거쳤을 때값 입력
	}
	for (int k = 1; k <= n - 2; k++) {								//부분 집합의 개수 (1개부터 n-2개)
		for (set = 2; set < pow(2, n); set++) {						//모든 부분집합 (부분집합의 개수는 2^n 개)
			if ((set & 1) == 0 && bitcnt(set) == k) {				//집합에 v1이 포합되어 있지 않고, 원소의 개수가 k개 이면
				for (int i = 2; i <= n; i++) {						//i=1 제외한 모든 i
					if (((1 << (i - 1)) & set) == 0) {				//i가 집합에 없으면
						int temp_min = inf;							//임시 최소값
						for (int j = 1; j <= n; j++) {				//n까지 모든 j
							if (((1 << (j - 1)) & set)) {			//j가 집합에 포함되어 있으면
								if (temp_min > W[i][j] + D[j][set ^ (1 << (j - 1))]) {	//D[i][set]의 최소값 구하기 set에서 vj를 포함하지 않는 집합
									temp_min = W[i][j] + D[j][set ^ (1 << (j - 1))];		//D[i][set]은 W[i][j] + D[j][set ^ (1 << (j - 1))] 의 최소값
									p[i][set] = j;										//최소값을 주는 j의 값
								}
							}
						}
						D[i][set] = temp_min;											//D[i][set]의 최소값
					}
				}
			}
		}
	}
	int V = pow(2, n) - 2;											//1을 제외한 모든 원소를 가진 집합
	D[1][V] = inf;												    //임시 최소값
	for (int j = 2; j <= n; j++) {									//n까지의 모든 j
		if (D[1][V] > W[1][j] + D[j][V ^ (1 << (j - 1))]) {			//D[1][V]의 최소값 구하기 V에서 vj를 포함하지 않는 집합
			D[1][V] = W[1][j] + D[j][V ^ (1 << (j - 1))];			//D[1][V]의 최소값은 W[1][j] + D[j][V ^ (1 << (j - 1))]의 최소값
			p[1][V] = j;											//최소값을 주는 j의 값
		}
	}
	minlength = D[1][V];											//최소 길이	

	cout << "TSP 실행결과\n";
	if (minlength != inf) {												//경로가 있을 경우
		cout << "경로를 출력하겠습니다.\n";								//경로 출력
		cout << 1 << " -> ";											//처음은 무조건 1
		int j = 1;														//중간값 저장
		for (int i = 0; i < n - 1; i++) {									//n-1개 만큼출력
			cout << p[j][V] << " -> ";									//j에서 V까지 가는데 최소 경로
			j = p[j][V];
			V = V ^ (1 << (j - 1));
		}
		cout << 1 << endl;												//마지막은 무조건 1
		cout << "최소 길이를 출력하겠습니다. \n";
		cout << minlength << endl;
	}
	else																//경로가 없을 경우
		cout << "경로가 없습니다.\n";
}