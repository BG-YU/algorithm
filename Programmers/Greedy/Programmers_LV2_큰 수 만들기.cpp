/*
https://programmers.co.kr/learn/courses/30/lessons/42883
[문제 설명]
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 
이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. 
number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

[제한 조건]
number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.

[입출력 예]
number     k return
1924       2 94
1231234    3 3234
4177252841 4 775841
*/
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> vect;
    bool flag = true;
    int cnt = number.length() - k;

    for (int i = 0; i < number.length(); i++) {
        vect.push_back(number[i]);
        
        if (vect.size() > 1) {
            if (k == 0) continue;
            while (1) {
                if (k == 0) break;
                if (vect.size() <= 1) break;
                int len = vect.size();
                if (vect[len - 1] > vect[len - 2]) {
                    vect.pop_back();
                    vect.pop_back();
                    vect.push_back(number[i]);
                    k--;
                }
                else break;
            }
        }
    }

    for (int i = 0; i < vect.size(); i++) answer += vect[i];
    for (int i = 0; i < vect.size() - 1; i++) {
        if (vect[i] != vect[i + 1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        answer = "";
        for (int i = 0; i < cnt; i++) {
            answer += vect[0];
        }
    }

    if (k > 0) answer = answer.substr(0, answer.length() - k);

    return answer;
}

int main() {
    solution("4177252841", 4); // 정답 : 775841
    //solution("00001000", 5); // 정답 : 100
    //solution("0000", 2); // 정답 : 00
    return 0;
}