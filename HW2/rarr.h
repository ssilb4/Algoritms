#ifndef RARR_H
#define RARR_H
#include "node.h"


class rarr {						//r ���� Ŭ����
	char key[max_size];				//��� ��ǥ�� (���ĺ����� ǥ����)
	int index;						//Ʈ�� �ε���
public:
	rarr();							//������
	int r[max_size][max_size];		//r ���
	node* BuildTree(int i, int j);	//���� ���� Ʈ�� ����
	void print_r(int size);			//r ��� ���
	void print_tree(node* tree, int index);		//Ʈ�� ����Լ�
};
#endif