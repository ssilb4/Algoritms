#include "Aarr.h"

Aarr::Aarr() {								//생성자, A행렬 초기화
	for (int i = 0; i < max_size; i++) {
		for (int j = 0; j < max_size; j++) {
			A[i][j] = 0;					//0으로 초기화
		}
	}
}
double Aarr::OptimalBST(double p[], int r[][max_size], int n) {		//최적이진탐색 트리 알고리즘
	for (int i = 1; i <= n; i++) {
		A[i][i] = p[i];									//A의 처음 값(i-i)들을 처음 확률로 입력
		r[i][i] = i;									//r의 처음 값(i-i)들을 인덱스값
	}
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n - h; i++) {
			int j = i + h;
			double temp = 99999999;						//최소값을 저장하기 위함 임시값
			int temp3;									//최소값의 인덱스를 저장하기 위한 임시값
			for (int k = i; k <= j; k++) {
				if (A[i][k - 1] + A[k + 1][j] < temp) {	//현재 최소값보다 작으면
					temp = A[i][k - 1] + A[k + 1][j];	//그 값을 현재 최소값으로
					temp3 = k;							//그 때의 인덱스값
				}
			}
			double temp2 = 0;							//범위내의 확률의 합 저장
			for (int k = i; k <= j; k++) {
				temp2 += p[k];							//확률의 합
			}
			A[i][j] = temp + temp2;						//확률의 합과 최소값을 A행렬에 삽입
			r[i][j] = temp3;							//r행렬에는 최소값일 때의 인덱스값 삽입
		}
	}
	return A[1][n];										//최종값 반환
}
void Aarr::print_A(int size) {							//A행렬 출력
	cout << endl << "A행렬" << endl;
	for (int a = 1; a <= size; a++) {
		for (int b = 1; b <= size; b++) {
			cout.precision(1);							//소수 첫번째짜리 까지
			cout << fixed << setw(3) << A[a][b] << " ";	//줄 맞춰서 출력
		}
		cout << endl;
	}
	cout << endl;
}