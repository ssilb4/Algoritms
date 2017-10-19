#include "function.h"
#include <math.h> 
int bitcnt(int n) {//����̾� Ŀ�ϰ��� ��Ʈ ī��Ʈ
	int c, v = n;
	for (c = 0; v; c++)
	{
		v &= v - 1; // clear the least significant bit set
	}
	return c;														//��Ʈ ���� ����
}

void tsp(int n, int W[][100], int p[][100], int& minlength) {		//tsp �˰���
	int D[100][100];												//�߰� ��ε� ���
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			D[i][j] = inf;											//inf�� �ʱ�ȭ
		}
	}
	int set;														//������ ��Ÿ���� set (��Ʈ�� 1�̸� ������ ����)
	for (int i = 2; i <= n; i++) {
		D[i][0] = W[i][1];											//�ϳ��� �� ������ ���� �Է�
	}
	for (int k = 1; k <= n - 2; k++) {								//�κ� ������ ���� (1������ n-2��)
		for (set = 2; set < pow(2, n); set++) {						//��� �κ����� (�κ������� ������ 2^n ��)
			if ((set & 1) == 0 && bitcnt(set) == k) {				//���տ� v1�� ���յǾ� ���� �ʰ�, ������ ������ k�� �̸�
				for (int i = 2; i <= n; i++) {						//i=1 ������ ��� i
					if (((1 << (i - 1)) & set) == 0) {				//i�� ���տ� ������
						int temp_min = inf;							//�ӽ� �ּҰ�
						for (int j = 1; j <= n; j++) {				//n���� ��� j
							if (((1 << (j - 1)) & set)) {			//j�� ���տ� ���ԵǾ� ������
								if (temp_min > W[i][j] + D[j][set ^ (1 << (j - 1))]) {	//D[i][set]�� �ּҰ� ���ϱ� set���� vj�� �������� �ʴ� ����
									temp_min = W[i][j] + D[j][set ^ (1 << (j - 1))];		//D[i][set]�� W[i][j] + D[j][set ^ (1 << (j - 1))] �� �ּҰ�
									p[i][set] = j;										//�ּҰ��� �ִ� j�� ��
								}
							}
						}
						D[i][set] = temp_min;											//D[i][set]�� �ּҰ�
					}
				}
			}
		}
	}
	int V = pow(2, n) - 2;											//1�� ������ ��� ���Ҹ� ���� ����
	D[1][V] = inf;												    //�ӽ� �ּҰ�
	for (int j = 2; j <= n; j++) {									//n������ ��� j
		if (D[1][V] > W[1][j] + D[j][V ^ (1 << (j - 1))]) {			//D[1][V]�� �ּҰ� ���ϱ� V���� vj�� �������� �ʴ� ����
			D[1][V] = W[1][j] + D[j][V ^ (1 << (j - 1))];			//D[1][V]�� �ּҰ��� W[1][j] + D[j][V ^ (1 << (j - 1))]�� �ּҰ�
			p[1][V] = j;											//�ּҰ��� �ִ� j�� ��
		}
	}
	minlength = D[1][V];											//�ּ� ����	

	cout << "TSP ������\n";
	if (minlength != inf) {												//��ΰ� ���� ���
		cout << "��θ� ����ϰڽ��ϴ�.\n";								//��� ���
		cout << 1 << " -> ";											//ó���� ������ 1
		int j = 1;														//�߰��� ����
		for (int i = 0; i < n - 1; i++) {									//n-1�� ��ŭ���
			cout << p[j][V] << " -> ";									//j���� V���� ���µ� �ּ� ���
			j = p[j][V];
			V = V ^ (1 << (j - 1));
		}
		cout << 1 << endl;												//�������� ������ 1
		cout << "�ּ� ���̸� ����ϰڽ��ϴ�. \n";
		cout << minlength << endl;
	}
	else																//��ΰ� ���� ���
		cout << "��ΰ� �����ϴ�.\n";
}