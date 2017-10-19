#include "dp_knapsack.h"
#include "ga_knapsack.h"

int main() {
	clock_t start_time, end_time;        //시간저장변수
	system("mode con:cols=100 lines=35");

	//for (int t = 0; t < 5; t++) {		//5번 반복
		int n;							//item의 개수
		int W;							//최대 무게
		/*cout << "item의 개수를 입력하세요.(최대 10개)\n";
		cin >> n;
		cout << "최대 무게를 입력하세요.\n";
		cin >> W;*/
		n = 5; W = 70;
		cout << "item = 5, W = 70" << endl;
		int w[11] = { 0, };							//item 당 무게
		int price[11] = { 0, };						//item 당 가격

		w[1] = 5; w[2] = 10; w[3] = 20; w[4] = 30; w[5] = 35;
		price[1] = 50; price[2] = 60; price[3] = 140; price[4] = 200; price[5] = 240;
		for (int i = 0; i < n; i++) {
			/*cout << i+1 <<"번째 item의 무게과 값을 차례로 입력해주세요.\n";
			cin >> w[i + 1];
			cin >> price[i + 1];*/
			cout << i + 1 << "번째 item의 무게: " << w[i + 1] << " 가격: " << price[i + 1] << endl;
		}
		cout << "유전자 개수: 30, 세대 수: 4" << endl;
		Sleep(2000);
		system("cls");
		/*
		dp_knap my1;								//dp로 된 knapsack
		start_time = clock();						 //측정 시작
		my1.dp(price, w, n, W);		//결과 출력
		end_time = clock();						  //측정 종료
		//cout << "DP시간: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl; //걸린시간 출력
		*/
		
		ga_knap my2(n);								//GA로 된 knapsack

		start_time = clock();                    //측정 시작
		for (int i = 0; i < 4; i++) {			//700세대
			my2.fit(price, w, W);				//fitness 계산
			my2.scaling();						//scaling
			my2.select();						//selection
			my2.crossover();					//crossoveer
			my2.mutation();						//mutation
		}
		end_time = clock();                     //측정 종료	
		cout << "결과: ";
		my2.print_result(price);				//결과 출력
		//cout << "GA시간: "<< (double)(end_time - start_time) / CLOCKS_PER_SEC << endl; //걸린시간 출력
		cout << endl;
	
	//}
}