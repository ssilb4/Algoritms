#include "sort.h"

int main(){
	for (int t = 0; t < 8; t++){		//한 번 실행으로 8번의 데이터를 비교하기 위해
		int k;
		cin >> k;						//데이터 개수
		srand((unsigned)time(NULL));	//랜덤 입력을 위한 
		mysort ex1;						//기본 Quick Sort를 위한 객체
		mysort ex2;						//Median-of-three Quick Sort을 위한 객체
		ex1.arr = new int[k];			//개수 입력받은 개수만큼 할당
		ex2.arr = new int[k];			//개수 입력받은 개수만큼 할당
		for (int i = 0; i < k; i++){	//데이터 입력
			int num = rand();
			ex1.insert(num);
			ex2.insert(num);
		}
		long startTime;					//시작시간 저장하기 위한 변수
		long finishTime;				//시작시간 저장하기 위한 변수
		startTime = clock();			//시작시간 기록
		ex1.Qsort(ex1.arr, 0, k - 1);	//Quick Sort 실행
		finishTime = clock();			//종료시간 기록
		cout << k << "개 기본 퀵소트: "
			<< finishTime - startTime << endl;	//시간 출력
		startTime = clock();			//시간시간 기록
		ex2.MedianQsort(ex2.arr, 0, k - 1);	//Median-of-three Quick Sort 실행
		finishTime = clock();			//종료시간 기록
		cout << k << "개 3 메디안 퀵소트: "
			<< finishTime - startTime << endl;	//시간 출력
	}
	return 0;
}
