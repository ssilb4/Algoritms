#include "rarr.h"	//r ��� ����
#include "Aarr.h"	//A ��� ����
int main() {
	Aarr myA[5];	// A��� ���� Ŭ����
	rarr myr[5];	// r��� ���� Ŭ����
	int size;		// ��� ũ��
	double p[max_size] = { 0, };	//�� ����� Ȯ��
	for (int i = 0; i < 5; i++) {		// 5���� ��
		cout << "����� ���� �Է�(26����): ";
		cin >> size;					//��� ���� �Է�
		cout << endl;
		cout << "�ε����� Ȯ���� ������� �Է�" << endl;
		for (int j = 1; j <= size; j++) {
			cin >> p[j];								//��庰 Ȯ�� �Է�
		}
		cout << endl;
		myA[i].OptimalBST(p, myr[i].r, size);			//���� ���� Ž�� Ʈ�� �˰���
		myA[i].print_A(size);							//A ��� ���
		myr[i].print_r(size);							//r ��� ���
		myr[i].print_tree(myr[i].BuildTree(1, size),1);	//���� ���� Ž�� Ʈ�� ���
	}
	return 0;
}