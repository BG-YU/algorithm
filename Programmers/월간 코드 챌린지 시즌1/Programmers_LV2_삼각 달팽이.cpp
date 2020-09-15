﻿/*
https://programmers.co.kr/learn/courses/30/lessons/68645
[문제 설명]
정수 n이 매개변수로 주어집니다.
다음 그림과 같이 밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후,
첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return 하도록 solution 함수를 완성해주세요.

=====================================
1               1
2  9            2 15
3 10 8          3 16 14
4  5 6 7        4 17 21 13
                5 18 19 20  12
                6  7  8  9  10  11
  [n = 4]           [n = 6]
=====================================

[제한사항]
n은 1 이상 1,000 이하입니다.

[입출력 예]
n	result
4	[1,2,9,3,10,8,4,5,6,7]
5	[1,2,12,3,13,11,4,14,15,10,5,6,7,8,9]
6	[1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11]
*/
#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    int y = 0, x = 0;
    int cnt = n, num = 1;

    while (1) {
        for (int i = 0; i < cnt; i++) {
            arr[y++][x] = num++;
        }
        y--;
        x++;
        cnt--;
        if (cnt == 0) break;

        for (int i = 0; i < cnt; i++) {
            arr[y][x++] = num++;
        }
        y--;
        x -= 2;
        cnt--;
        if (cnt == 0) break;

        for (int i = 0; i < cnt; i++) {
            arr[y--][x--] = num++;
        }
        y += 2;
        x++;
        cnt--;
        if (cnt == 0) break;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (arr[i][k] == 0) continue;
            answer.push_back(arr[i][k]);
        }
    }

    return answer;
}

int main() {
    solution(6);
    return 0;
}