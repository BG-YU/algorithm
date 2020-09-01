/*
https://programmers.co.kr/learn/courses/30/lessons/12916
[문제 설명]
대문자와 소문자가 섞여있는 문자열 s가 주어집니다. 
s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요. 
'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 
단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.

예를 들어 s가 pPoooyY면 true를 return하고 Pyy라면 false를 return합니다.

[제한사항]
문자열 s의 길이 : 50 이하의 자연수
문자열 s는 알파벳으로만 이루어져 있습니다.

[입출력 예]
s        answer
pPoooyY  true
Pyy      false
*/

#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int pcnt = 0, ycnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'Y' || s[i] == 'y') ycnt++;
        if (s[i] == 'P' || s[i] == 'p') pcnt++;
    }

    if (ycnt == pcnt) return true;
    else return false;
}


int main() {
    solution("pPoooyY");
    return 0;
}