# [Diamond V] 배열의 특징 - 14180 

[문제 링크](https://www.acmicpc.net/problem/14180) 

### 성능 요약

메모리: 8272 KB, 시간: 32 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍, 누적 합

### 제출 일자

2024년 7월 3일 14:34:49

### 문제 설명

<p>길이가 N인 정수 배열 A가 주어진다. 배열의 특징 C는 ΣA<sub>i</sub>·i (1 ≤ i ≤ n) 으로 정의된다.</p>

<p>배열에서 수 하나를 고른 다음, 아무 위치로 이동시킬 수 있다. 이때, 배열의 시작이나 끝으로도 옮길 수 있으며, 원래 위치로도 옮길 수 있다.</p>

<p>배열 A에서 수를 하나만 이동시켰을 때, 배열의 특징 C의 최댓값을 구하는 프로그램을 작성하시오. </p>

### 입력 

 <p>첫째 줄에 N (2 ≤ N ≤ 200,000)이 주어진다.</p>

<p>둘째 줄에는 A<sub>i</sub> (|A<sub>i</sub>| ≤ 1,000,000)가 주어진다.</p>

### 출력 

 <p>배열에서 수를 하나만 움직인 후의 C의 최댓값을 출력한다.</p>

