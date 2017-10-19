#include "function.h"

int main() {
	for (int t = 0; t < 5; t++) {
		int map[100][100] = { 0, };										//행렬
		int p[100][100] = { 0, };										//플로이드의 중간 행렬
		cout << "그래프의 크기를 입력하세요.\n";
		int n;															//행렬의 크기
		cin >> n;
		cout << "그래프를 입력하세요. (무한은 -1)\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int num;												//가중치
				cin >> num;												//각 그래프의 노드의 가중치 입력
				if (num == -1)											//가중치가 -1 인 경우
					map[i][j] = inf;									//inf
				else													//그 밖의 경우
					map[i][j] = num;									//그 외는 무한대로
			}
		}
		int minlength = inf;											//tsp 최소 길이
		floyd(n,map,p);													//플로이드 실행
		tsp(n,map,p,minlength);											//tsp 실행
	}
	return 0;
}
