#include "rarr.h"

rarr::rarr() {				//������ key��, r �ʱ�ȭ
	for (int i = 0; i < max_size-1; i++) {
		key[i+1] = 'A' + i;				//key ���� ���ĺ� ������� �ʱ�ȭ
	}
	for (int i = 0; i < max_size; i++) {
		for (int j = 0; j < max_size; j++) {
			r[i][j] = 0;				//r �� 0���� �ʱ�ȭ
		}
	}
	index = 1;							//index �� 1�� �ʱ�ȭ
}

node* rarr::BuildTree(int i, int j) {		// ���� ���� Ž�� Ʈ�� ����
	int k;									// r��
	node* p;								// Ʈ���� ���� ���
	k = r[i][j];							// �ʱⰪ ����
	if (k == 0) return 0;					// k �� 0�̸� 0
	else {
		p = new node;						//�����Ҵ�
		p->key = key[k];					//Ű �� �Է�
		p->left = BuildTree(i, k - 1);		//���� �ڽ�
		p->right = BuildTree(k + 1, j);		//������ �ڽ�
		return p;							//����
	}
}
void rarr::print_r(int size) {				//r ��� ���
	cout << "R���" << endl;
	for (int a = 1; a <= size; a++) {
		for (int b = 1; b <= size; b++) {
			cout.precision(1);				//�Ҽ��� ù°¥�� ������ ���
			cout << fixed << setw(3) << r[a][b] << " ";	//ĭ ����
		}
		cout << endl;
	}
	cout << endl;
}
void rarr::print_tree(node* tree, int index) {			//Ʈ�� ���
	if (tree != NULL) {									//Ʈ���� NULL�� �ƴϸ�
		cout << "index: "<< index << ", key: " << tree->key << endl;	//�ε����� Ű ���
		print_tree(tree->left, index * 2);								//���� ���� �ε��� *2
		print_tree(tree->right, index * 2 + 1);							//������ ���� �ε���*2+1
	}
}