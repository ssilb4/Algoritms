#ifndef GENE_H
#define GENE_H
struct _gene {					//하나의 유전자
	int population[100];		//최대 길이는 100, 인코딩은 2진수로 1은 선택됨, 0은 선택되지 않음
	int fitness;				//각 유전자 당 fitness
};
bool compare(_gene& a, _gene& b);

#endif