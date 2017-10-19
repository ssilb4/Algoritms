#include "ga_knapsack.h"

int ga_knap::random() {			//난수 생성 함수
	time_t seconds;				//시간
	time(&seconds);				//시간 변경
	srand((unsigned int)seconds);//계속 다른 난수를 만들기 위해
	return rand() % 99999;			//난수 리턴
}
ga_knap::ga_knap() {				//g디폴트 생성자
}
ga_knap::ga_knap(int n) {			//유전자의 길이가 n일 때의 생성자
	size = n;						//size = n
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < n; j++) {
			gene[i].population[j] = rand() % 2;	//1,0 으로 인코딩하기 위해서 rand%2 를 해서 초기화
		}
	}
	generation = 0;
}
void ga_knap::fit(int p[], int w[],int W) {						//fitness 구하는 함수
	int weight[100] = { 0, };									//유전자별 무게
	int price[100] = { 0, };									//유전자별 가격
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			price[i] += gene[i].population[j] * p[j+1];			//한 유전자의 population*가격을 저장
			weight[i] += gene[i].population[j] * w[j+1];		//한 유전자의 population*무게를 저장
		}
		gene[i].fitness = price[i];								//한 유전자의 fitness 는 총 가격 (가격이 높을 수록 fitness가 높다)
		if (weight[i] > W) {									//한 유전자의 총무게가 W를 초과한다면
			gene[i].fitness /= 10;								//fitness는 10분의 1 (무게가 초과하면 안 되므로 fitness를 낮춰준다.
		}
	}
}
void ga_knap::select() {			//Ranking selection
	for (int i = 0; i < number / 3; i++) {						//총 유전자의 3분의1
		gene[i] = gene[number - i - 1];							//하위 3분의 1을 상위 3분의 1과 바꿈
		cout << "selecton" << endl;
		print_gene();
	}
}
void ga_knap::crossover() {			//single point crossover
	for (int i = 0; i < number / 6; i++) {									//전체 유전자의 6분의 1
		for (int j = 0; j < size / 4; j++) {								//한 유전자의 크기의 4분의 1
			int temp = gene[i].population[j];								//바꿀 유전자 저장
			gene[i].population[j] = gene[i+number/6].population[j];			//유전자 교체
			gene[i + number / 6].population[j] = temp;						//저장한 유전자 교체
			cout << "crossover" << endl;
			print_gene();
		}
	}
}
void ga_knap::mutation() {			//insertion mutation
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			if (rand() < 300) {												//rand가 0일 때만 (적은 확률)
				int r = rand() % size;											//한 유전자의 인덱스
				int temp = gene[i].population[0];							//첫 번째 원소 저장
				for (int k = 0; k < r; k++) {
					gene[i].population[k] = gene[i].population[k + 1];		//선택된 유전자의 인덱스까지 다른 원소들을 한칸씩 이동
				}
				gene[i].population[r] = temp;								//마지막 자리에 첫번째 저장한 원소 저장
				cout << "mutation" << endl;
				print_gene();
			}
		}
	}
}
void ga_knap::scaling() {						//rank scaling
	sort(gene, gene + number, compare);			//적합도를 바탕으로 오름차순으로 저장 (rank)
	generation++;
	cout << generation << "세대 fitness" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			cout << gene[i].fitness << " ";
		}
		cout << endl;
	}
	Sleep(2000);
	system("cls");
}
void ga_knap::print_result(int p[]) {
	int max = 0;								//fitness의 최대값
	int index = 0;								//최대값일 때의 index
	for (int i = 0; i < number; i++) {
		if (max < gene[i].fitness) {			//현재 최대값보다 크다면
			max = gene[i].fitness;				//최대값 저장
			index = i;							//인덱스도 저장
		}
	}
	max = 0;									//다시 최대값 초기화
	for (int i = 0; i < size; i++) {
		max += gene[index].population[i] * p[i+1];		//fitness가 최대값일 때의 유전자의 가격 저장
	}
	cout << max << endl;								//가격 출력
}

void ga_knap::print_gene() {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			cout << gene[i].population[j];
		}
		cout << endl;
	}
	Sleep(1000);
	system("cls");
}