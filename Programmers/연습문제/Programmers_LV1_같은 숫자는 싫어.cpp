﻿/*
https://programmers.co.kr/learn/courses/30/lessons/12906
문제 설명
배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 
이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 
단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 
예를 들면,

arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.

배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

[제한사항]
배열 arr의 크기 : 1,000,000 이하의 자연수
배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수

입출력 예
입력
[1,1,3,3,0,1,1]	
출력
[1,3,0,1]

입력
[4,4,4,3,3]
출력
[4,3]
*/
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) continue;
        answer.push_back(arr[i]);
    }

    return answer;
}

int main() {
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(3);
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);

    tmp = solution(tmp);

    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i] << " ";
    }

    return 0;
}