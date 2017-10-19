#include "ga_knapsack.h"

int ga_knap::random() {			//���� ���� �Լ�
	time_t seconds;				//�ð�
	time(&seconds);				//�ð� ����
	srand((unsigned int)seconds);//��� �ٸ� ������ ����� ����
	return rand() % 99999;			//���� ����
}
ga_knap::ga_knap() {				//g����Ʈ ������
}
ga_knap::ga_knap(int n) {			//�������� ���̰� n�� ���� ������
	size = n;						//size = n
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < n; j++) {
			gene[i].population[j] = rand() % 2;	//1,0 ���� ���ڵ��ϱ� ���ؼ� rand%2 �� �ؼ� �ʱ�ȭ
		}
	}
	generation = 0;
}
void ga_knap::fit(int p[], int w[],int W) {						//fitness ���ϴ� �Լ�
	int weight[100] = { 0, };									//�����ں� ����
	int price[100] = { 0, };									//�����ں� ����
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			price[i] += gene[i].population[j] * p[j+1];			//�� �������� population*������ ����
			weight[i] += gene[i].population[j] * w[j+1];		//�� �������� population*���Ը� ����
		}
		gene[i].fitness = price[i];								//�� �������� fitness �� �� ���� (������ ���� ���� fitness�� ����)
		if (weight[i] > W) {									//�� �������� �ѹ��԰� W�� �ʰ��Ѵٸ�
			gene[i].fitness /= 10;								//fitness�� 10���� 1 (���԰� �ʰ��ϸ� �� �ǹǷ� fitness�� �����ش�.
		}
	}
}
void ga_knap::select() {			//Ranking selection
	for (int i = 0; i < number / 3; i++) {						//�� �������� 3����1
		gene[i] = gene[number - i - 1];							//���� 3���� 1�� ���� 3���� 1�� �ٲ�
		cout << "selecton" << endl;
		print_gene();
	}
}
void ga_knap::crossover() {			//single point crossover
	for (int i = 0; i < number / 6; i++) {									//��ü �������� 6���� 1
		for (int j = 0; j < size / 4; j++) {								//�� �������� ũ���� 4���� 1
			int temp = gene[i].population[j];								//�ٲ� ������ ����
			gene[i].population[j] = gene[i+number/6].population[j];			//������ ��ü
			gene[i + number / 6].population[j] = temp;						//������ ������ ��ü
			cout << "crossover" << endl;
			print_gene();
		}
	}
}
void ga_knap::mutation() {			//insertion mutation
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			if (rand() < 300) {												//rand�� 0�� ���� (���� Ȯ��)
				int r = rand() % size;											//�� �������� �ε���
				int temp = gene[i].population[0];							//ù ��° ���� ����
				for (int k = 0; k < r; k++) {
					gene[i].population[k] = gene[i].population[k + 1];		//���õ� �������� �ε������� �ٸ� ���ҵ��� ��ĭ�� �̵�
				}
				gene[i].population[r] = temp;								//������ �ڸ��� ù��° ������ ���� ����
				cout << "mutation" << endl;
				print_gene();
			}
		}
	}
}
void ga_knap::scaling() {						//rank scaling
	sort(gene, gene + number, compare);			//���յ��� �������� ������������ ���� (rank)
	generation++;
	cout << generation << "���� fitness" << endl;
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
	int max = 0;								//fitness�� �ִ밪
	int index = 0;								//�ִ밪�� ���� index
	for (int i = 0; i < number; i++) {
		if (max < gene[i].fitness) {			//���� �ִ밪���� ũ�ٸ�
			max = gene[i].fitness;				//�ִ밪 ����
			index = i;							//�ε����� ����
		}
	}
	max = 0;									//�ٽ� �ִ밪 �ʱ�ȭ
	for (int i = 0; i < size; i++) {
		max += gene[index].population[i] * p[i+1];		//fitness�� �ִ밪�� ���� �������� ���� ����
	}
	cout << max << endl;								//���� ���
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