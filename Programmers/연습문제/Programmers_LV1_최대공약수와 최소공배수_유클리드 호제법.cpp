﻿/*
https://programmers.co.kr/learn/courses/30/lessons/12940
[문제 설명]
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요. 
배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

제한 사항
두 수는 1이상 1000000이하의 자연수입니다.

[입출력 예]
n	m	return
3	12	[3, 12]
2	5	[1, 10]

유클리드 호제법
http://lonpeach.com/2017/11/12/Euclidean-algorithm/
*/
#include <iostream>
#include <vector>
using namespace std;

int Euclidean(int a, int b)
{
    return b ? Euclidean(b, a % b) : a;
}

vector<int> solution(int n, int m)
{
    vector<int> answer;
    // 유클리드 호제법
    answer.push_back(Euclidean(n, m));

    answer.push_back(n * m / answer[0]);

    return answer;
}

int main() {
    solution(11, 7);
    return 0;
}

