#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
using namespace std;
const int max_size = 27;				//�ִ�ũ�� (���ĺ����� + 1)

class node {
public:
	char key;			//��尪
	node* left;			//���� �ڽ�
	node* right;		//������ �ڽ�
};

#endif