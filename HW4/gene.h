#ifndef GENE_H
#define GENE_H
struct _gene {					//�ϳ��� ������
	int population[100];		//�ִ� ���̴� 100, ���ڵ��� 2������ 1�� ���õ�, 0�� ���õ��� ����
	int fitness;				//�� ������ �� fitness
};
bool compare(_gene& a, _gene& b);

#endif