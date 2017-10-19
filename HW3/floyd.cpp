#include "function.h"

void floyd(int n, int temp[][100], int p[][100]) {
	int map[100][100];					//�÷��̵� ������ ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = temp[i][j];		//�ʱ�ȭ
			p[i][j] = 0;				//p �ʱ�ȭ
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] == inf) break;		//�ݺ�Ƚ���� ���̱� ���� ���ǹ��� �κ� break;
				if (map[i][j] > map[i][k] + map[k][j]) {	//�� ª�� �Ÿ� �߽߰�
					map[i][j] = map[i][k] + map[k][j];		//�� ��ȭ
					p[i][j] = k;							//�������
				}
			}
		}
	}

	cout << "�÷��̵� ���� ���\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == inf) cout << setw(3) << "x";	//���Ѵ�(�� �� ���� ���)�� ���� x �� ���
			else cout << setw(3) << map[i][j];			//�� �ܿ��� ����ġ�� ���
		}
		cout << endl;
	}

	cout << "��� ��� ���\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j] << " ";							//��� ��� ���
		}
		cout << endl;
	}
}