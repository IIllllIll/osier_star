# [Gold II] Magic Cards - 30858 

[문제 링크](https://www.acmicpc.net/problem/30858) 

### 성능 요약

메모리: 27964 KB, 시간: 1556 ms

### 분류

애드 혹, 브루트포스 알고리즘, 자료 구조, 해시를 사용한 집합과 맵, 구현

### 제출 일자

2024년 10월 12일 14:43:24

### 문제 설명

<p>Chansu and Junsu are friends in International College of Programming Convergence. One day, Chansu met Junsu and said that “I’ll do a magic trick for you. Pick any number between $1$ and $12$, and don’t tell me your number. Just keep it in your mind.” Junsu chose $11$ in mind. Chansu then showed Junsu the following four cards one by one, asking “Is there your number in this card?” at each time.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a4636ca4-cece-46ec-8bb5-ce18f52966e8/-/preview/" style="width: 467px; height: 72px;"></p>

<p>So, Junsu answered “Yes, yes, no, yes” in this order. After Chansu did some magically looking gestures with his arms and legs for a while, he finally shouted, “I’ve got your number. It is $11$.” And Junsu was quite surprised because it was exactly the number he kept in mind.</p>

<p>Chansu didn’t tell Junsu the secret of the trick, but only “These cards have a great magic power, so they can read your mind and tell me something only in a magical language, which only I can understand.”</p>

<p>How does this work? Can you figure out the secret?</p>

<p>Now, you are to write a program that answers the number in your friends’ minds. We can generalize the magic trick as follows: You have $K$ magic cards in each of which exactly $M$ integers between $1$ and $N$, possibly with some redundancy, are written, and you perform the magic trick to $F$ friends. From the yes/no-sequences from the $F$ friends, you will be able to pick out the correct numbers.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing four integers, $N$, $K$, $M$, and $F$ ($1 ≤ N ≤ 500\,000$, $1 ≤ K ≤ 100$, $1 ≤ M ≤ 5\,000$, $1 ≤ F ≤ 50\,000$). In each of the following $K$ lines, there are $M$ integers between $1$ and $N$, which represent the $M$ numbers written in each magic card. In each of the following $F$ lines, you are given a string of length $K$ over {<code>Y</code>, <code>N</code>}, which represents the answer of each friend such that a <code>Y</code> means a “yes” and an <code>N</code> means a “no”. You can assume that all the answers from the friends are correctly given according to their numbers chosen in mind.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly $F$ lines. For each $i = 1,2, \dots , F$, the $i$-th line should consists of the number in the $i$-th friend’s mind. If it is impossible to identify the one and only number of the $i$-th friend, print out <code>0</code> in the $i$-th line.</p>

