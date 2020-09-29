/*
https://programmers.co.kr/learn/courses/30/lessons/12951
[문제 설명]
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

[제한 조건]
s는 길이 1 이상인 문자열입니다.
s는 알파벳과 공백문자(" ")로 이루어져 있습니다.
첫 문자가 영문이 아닐때에는 이어지는 영문은 소문자로 씁니다. ( 첫번째 입출력 예 참고 )

[입출력 예]
s                       return
3people unFollowed me   3people Unfollowed Me
for the last week       For The Last Week
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int a = 0, b;
    s.insert(s.length(), " ");

    while (1) {
        b = s.find(' ', a);
        if (b == -1) break;

        if (s[a] >= 'a' && s[a] <= 'z') s[a] = (char)(s[a] - ('a' - 'A'));

        for (int i = a + 1; i <= b; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = (char)(s[i] + ('a' - 'A'));
        }

        a = b + 1;
    }

    return s.erase(s.length() - 1);
}

int main() {
    solution("3people unFollowed me");
    return 0;
}