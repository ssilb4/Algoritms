#include "gene.h"

bool compare(_gene& a, _gene& b) {				//fitness������ �����ڵ��� �����ϱ� ���� compare �Լ�
	if (a.fitness < b.fitness)					//�ڰ� �� ũ��
		return true;							//true
	else										//�ƴϸ�
		return false;							//false
}