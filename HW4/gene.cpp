#include "gene.h"

bool compare(_gene& a, _gene& b) {				//fitness순으로 유전자들을 저장하기 위한 compare 함수
	if (a.fitness < b.fitness)					//뒤가 더 크면
		return true;							//true
	else										//아니면
		return false;							//false
}