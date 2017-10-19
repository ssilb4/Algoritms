#include "Aarr.h"

Aarr::Aarr() {								//������, A��� �ʱ�ȭ
	for (int i = 0; i < max_size; i++) {
		for (int j = 0; j < max_size; j++) {
			A[i][j] = 0;					//0���� �ʱ�ȭ
		}
	}
}
double Aarr::OptimalBST(double p[], int r[][max_size], int n) {		//��������Ž�� Ʈ�� �˰���
	for (int i = 1; i <= n; i++) {
		A[i][i] = p[i];									//A�� ó�� ��(i-i)���� ó�� Ȯ���� �Է�
		r[i][i] = i;									//r�� ó�� ��(i-i)���� �ε�����
	}
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n - h; i++) {
			int j = i + h;
			double temp = 99999999;						//�ּҰ��� �����ϱ� ���� �ӽð�
			int temp3;									//�ּҰ��� �ε����� �����ϱ� ���� �ӽð�
			for (int k = i; k <= j; k++) {
				if (A[i][k - 1] + A[k + 1][j] < temp) {	//���� �ּҰ����� ������
					temp = A[i][k - 1] + A[k + 1][j];	//�� ���� ���� �ּҰ�����
					temp3 = k;							//�� ���� �ε�����
				}
			}
			double temp2 = 0;							//�������� Ȯ���� �� ����
			for (int k = i; k <= j; k++) {
				temp2 += p[k];							//Ȯ���� ��
			}
			A[i][j] = temp + temp2;						//Ȯ���� �հ� �ּҰ��� A��Ŀ� ����
			r[i][j] = temp3;							//r��Ŀ��� �ּҰ��� ���� �ε����� ����
		}
	}
	return A[1][n];										//������ ��ȯ
}
void Aarr::print_A(int size) {							//A��� ���
	cout << endl << "A���" << endl;
	for (int a = 1; a <= size; a++) {
		for (int b = 1; b <= size; b++) {
			cout.precision(1);							//�Ҽ� ù��°¥�� ����
			cout << fixed << setw(3) << A[a][b] << " ";	//�� ���缭 ���
		}
		cout << endl;
	}
	cout << endl;
}