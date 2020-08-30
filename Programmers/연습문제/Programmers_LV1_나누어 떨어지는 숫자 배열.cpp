/*
https://programmers.co.kr/learn/courses/30/lessons/12910
[문제 설명]
array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.

[제한사항]
arr은 자연수를 담은 배열입니다.
정수 i, j에 대해 i ≠ j 이면 arr[i] ≠ arr[j] 입니다.
divisor는 자연수입니다.
array는 길이 1 이상인 배열입니다.

[입출력 예]
arr              divisor return
[5, 9, 7, 10]    5       [5, 10]
[2, 36, 1, 3]    1       [1, 2, 3, 36]
[3,2,6]          10      [-1]
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)if (arr[i] % divisor == 0) answer.push_back(arr[i]);
    if (answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}


int main() {
    vector<int> tmp;
    tmp.push_back(5);
    tmp.push_back(9);
    tmp.push_back(7);
    tmp.push_back(10);

    tmp = solution(tmp, 5);

    for (int i = 0; i < tmp.size(); i++) cout << tmp[i];
    return 0;
}