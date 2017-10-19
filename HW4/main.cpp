#include "dp_knapsack.h"
#include "ga_knapsack.h"

int main() {
	clock_t start_time, end_time;        //�ð����庯��
	system("mode con:cols=100 lines=35");

	//for (int t = 0; t < 5; t++) {		//5�� �ݺ�
		int n;							//item�� ����
		int W;							//�ִ� ����
		/*cout << "item�� ������ �Է��ϼ���.(�ִ� 10��)\n";
		cin >> n;
		cout << "�ִ� ���Ը� �Է��ϼ���.\n";
		cin >> W;*/
		n = 5; W = 70;
		cout << "item = 5, W = 70" << endl;
		int w[11] = { 0, };							//item �� ����
		int price[11] = { 0, };						//item �� ����

		w[1] = 5; w[2] = 10; w[3] = 20; w[4] = 30; w[5] = 35;
		price[1] = 50; price[2] = 60; price[3] = 140; price[4] = 200; price[5] = 240;
		for (int i = 0; i < n; i++) {
			/*cout << i+1 <<"��° item�� ���԰� ���� ���ʷ� �Է����ּ���.\n";
			cin >> w[i + 1];
			cin >> price[i + 1];*/
			cout << i + 1 << "��° item�� ����: " << w[i + 1] << " ����: " << price[i + 1] << endl;
		}
		cout << "������ ����: 30, ���� ��: 4" << endl;
		Sleep(2000);
		system("cls");
		/*
		dp_knap my1;								//dp�� �� knapsack
		start_time = clock();						 //���� ����
		my1.dp(price, w, n, W);		//��� ���
		end_time = clock();						  //���� ����
		//cout << "DP�ð�: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl; //�ɸ��ð� ���
		*/
		
		ga_knap my2(n);								//GA�� �� knapsack

		start_time = clock();                    //���� ����
		for (int i = 0; i < 4; i++) {			//700����
			my2.fit(price, w, W);				//fitness ���
			my2.scaling();						//scaling
			my2.select();						//selection
			my2.crossover();					//crossoveer
			my2.mutation();						//mutation
		}
		end_time = clock();                     //���� ����	
		cout << "���: ";
		my2.print_result(price);				//��� ���
		//cout << "GA�ð�: "<< (double)(end_time - start_time) / CLOCKS_PER_SEC << endl; //�ɸ��ð� ���
		cout << endl;
	
	//}
}