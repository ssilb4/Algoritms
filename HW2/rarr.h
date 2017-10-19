#ifndef RARR_H
#define RARR_H
#include "node.h"


class rarr {						//r 관련 클래스
	char key[max_size];				//노드 대표값 (알파벳으로 표현함)
	int index;						//트리 인덱스
public:
	rarr();							//생성자
	int r[max_size][max_size];		//r 행렬
	node* BuildTree(int i, int j);	//최적 이진 트리 구축
	void print_r(int size);			//r 행렬 출력
	void print_tree(node* tree, int index);		//트리 출력함수
};
#endif