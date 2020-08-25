/*
https://programmers.co.kr/learn/courses/30/lessons/12921
[문제 설명]
1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.

소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
(1은 소수가 아닙니다.)

[제한 조건]
n은 2이상 1000000이하의 자연수입니다.

[입출력 예]
n	result
10	4
5	3

[key point]
에라토스테네스의 체
https://redcoder.tistory.com/48

1은 소수가 아니다.
2는 소수이다. -> 2의 배수는 소수가 아니다.
3은 소수이다. -> 3의 배수는 소수가 아니다.
4는 소수가 이미 아니다.
5는 소수이다. -> 5의 배수가 소수가 아니다.
... (반복)
*/
#include <iostream>

using namespace std;

int arr[1000000];

int solution(int n) {
    int cnt = 0;
    
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 1) continue;
        for (int k = i * 2; k <= n; k += i) {
            arr[k] = 1;
        }
    }

    for (int i = 2; i <= n; i++) if (arr[i] == 0) cnt++;

    return cnt;
}

int main() {
    cout << solution(10);
    return 0;
}