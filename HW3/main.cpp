#include "function.h"

int main() {
	for (int t = 0; t < 5; t++) {
		int map[100][100] = { 0, };										//���
		int p[100][100] = { 0, };										//�÷��̵��� �߰� ���
		cout << "�׷����� ũ�⸦ �Է��ϼ���.\n";
		int n;															//����� ũ��
		cin >> n;
		cout << "�׷����� �Է��ϼ���. (������ -1)\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int num;												//����ġ
				cin >> num;												//�� �׷����� ����� ����ġ �Է�
				if (num == -1)											//����ġ�� -1 �� ���
					map[i][j] = inf;									//inf
				else													//�� ���� ���
					map[i][j] = num;									//�� �ܴ� ���Ѵ��
			}
		}
		int minlength = inf;											//tsp �ּ� ����
		floyd(n,map,p);													//�÷��̵� ����
		tsp(n,map,p,minlength);											//tsp ����
	}
	return 0;
}
