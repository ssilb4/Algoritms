HW #1

제     목

정렬 알고리즘

최소한 아래의 내용을 포함할 것.
1. 개요

>

  (1) 기본 Quick Sort(강의자료의 in-place Quick sort)
  
  (2) Median-of-three Quick Sort

---------------------
2. 상세 설계내용

>

  (1) 기본 Quick Sort: 강의 노트에 있는 그대로 짰습니다.
  
  (2) Median-of-three Quick Sort: 기본 Quick Sort에서 뒤에 3개의 수 중 중간의 수를 피벗과 교환을 하는 형식으로 짰습니다.
  
  (3) k의 값은 50000, 100000, 500000, 1000000, 2500000, 5000000, 7500000, 10000000 으로 값을 다양하게 하여서 짰습니다.
  
  (4) 쿨럭을 재서 성능을 비교하였습니다.
 
------------------
3. 분석 및 결론

>

  (1) 예상한 것과 비슷하게 기본 Quick Sort에 비해 Median-of-three Quick Sort가 평균적으로 약간 더 빨랐지만 거의 비슷했습니다.
  
  (2) Odd-Even Sort의 경우에는 k가 작을 때는 Quick Sort에 비해 느렸지만 k가 많아지면 훨씬 더 빨랐습니다.
  
  (3) QuickSort의 경우 평균 nlogn 정도의 속도로 조금씩 증가량이 점점 늘어난다면, Odd-Even Sort는 거의 n 정도의 속도여서 그래프 모양이 직선이 됩니다.

