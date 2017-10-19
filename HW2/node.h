#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
using namespace std;
const int max_size = 27;				//최대크기 (알파벳개수 + 1)

class node {
public:
	char key;			//노드값
	node* left;			//왼쪽 자식
	node* right;		//오른쪽 자식
};

#endif