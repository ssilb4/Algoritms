#ifndef GA_KNAPSACK_H
#define HA_KNAPSACk_H

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ctime>        //완전한 난수를 위해서
#include <stdlib.h>    //난수 함수 쓰기 위해서
#include "gene.h"
#include <Windows.h>
using namespace std;

#define number 30			//유전자 개수


class ga_knap {									//GA를 이용한 kanapsack
private:
	_gene gene[100];							//유전자
	int size;									//크기
	int generation;
public:
	ga_knap();									//디폴트 생성자
	ga_knap(int n);								//유전자의 길이가 n
	int random();								//난수를 만드는 함수
	void fit(int p[], int w[], int W);			//fitness 계산함수
	void select();								//selection 함수
	void crossover();							//crossover(교배) 함수
	void mutation();							//mutation(돌연변이) 함수
	void scaling();								//scaling 함수
	void print_result(int p[]);					//결과 출력 함수
	void print_gene();
};



#endif