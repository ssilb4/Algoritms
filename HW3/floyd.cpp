#include "function.h"

void floyd(int n, int temp[][100], int p[][100]) {
	int map[100][100];					//플로이드 실행결과 행렬
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = temp[i][j];		//초기화
			p[i][j] = 0;				//p 초기화
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] == inf) break;		//반복횟수를 줄이기 위해 무의미한 부분 break;
				if (map[i][j] > map[i][k] + map[k][j]) {	//더 짧은 거리 발견시
					map[i][j] = map[i][k] + map[k][j];		//값 변화
					p[i][j] = k;							//경로저장
				}
			}
		}
	}

	cout << "플로이드 실행 결과\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == inf) cout << setw(3) << "x";	//무한대(갈 수 없는 경우)일 때는 x 를 출력
			else cout << setw(3) << map[i][j];			//그 외에는 가중치를 출력
		}
		cout << endl;
	}

	cout << "경로 행렬 결과\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j] << " ";							//경로 행렬 출력
		}
		cout << endl;
	}
}