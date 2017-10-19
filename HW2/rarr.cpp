#include "rarr.h"

rarr::rarr() {				//생성자 key와, r 초기화
	for (int i = 0; i < max_size-1; i++) {
		key[i+1] = 'A' + i;				//key 값을 알파벳 순서대로 초기화
	}
	for (int i = 0; i < max_size; i++) {
		for (int j = 0; j < max_size; j++) {
			r[i][j] = 0;				//r 은 0으로 초기화
		}
	}
	index = 1;							//index 는 1로 초기화
}

node* rarr::BuildTree(int i, int j) {		// 최적 이진 탐색 트리 구축
	int k;									// r값
	node* p;								// 트리를 위한 노드
	k = r[i][j];							// 초기값 저장
	if (k == 0) return 0;					// k 가 0이면 0
	else {
		p = new node;						//동적할당
		p->key = key[k];					//키 값 입력
		p->left = BuildTree(i, k - 1);		//왼쪽 자식
		p->right = BuildTree(k + 1, j);		//오른쪽 자식
		return p;							//종료
	}
}
void rarr::print_r(int size) {				//r 행렬 출력
	cout << "R행렬" << endl;
	for (int a = 1; a <= size; a++) {
		for (int b = 1; b <= size; b++) {
			cout.precision(1);				//소수점 첫째짜리 까지만 출력
			cout << fixed << setw(3) << r[a][b] << " ";	//칸 정렬
		}
		cout << endl;
	}
	cout << endl;
}
void rarr::print_tree(node* tree, int index) {			//트리 출력
	if (tree != NULL) {									//트리가 NULL이 아니면
		cout << "index: "<< index << ", key: " << tree->key << endl;	//인덱스와 키 출력
		print_tree(tree->left, index * 2);								//왼쪽 노드는 인덱스 *2
		print_tree(tree->right, index * 2 + 1);							//오른쪽 노드는 인덱스*2+1
	}
}