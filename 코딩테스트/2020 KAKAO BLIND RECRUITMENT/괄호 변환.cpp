/*
2020 KAKAO BLIND RECRUITMENT
괄호 변환
https://programmers.co.kr/learn/courses/30/lessons/60058
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int index = 0;

bool fn_chk(string p) {
    vector<char> vect;
    int cnt = 0, flag = 0;

    for (int i = 0; i < p.length(); i++) {
        vect.push_back((char)(p[i]));

        if ((char)(p[i]) == '(') cnt++;
        else cnt--;

        if (cnt == 0 && flag == 0) {
            index = i + 1;
            flag = 1;
        }

        if (vect.size() >= 2) {
            if (vect[vect.size() - 1] == ')' && vect[vect.size() - 2] == '(') {
                vect.pop_back();
                vect.pop_back();
            }
        }
    }

    if (vect.size() == 0) return true;
    else return false;
}

string solution(string p) {
    if (p == "") return p;
    if (fn_chk(p)) return p;

    string answer = "", temp = "";
    string u = "", v = "";

    for (int i = 0; i < index; i++) u += (char)(p[i]);
    for (int i = index; i < p.length(); i++) v += (char)(p[i]);

    if (fn_chk(u)) return u + solution(v);
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";

        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') answer += ')';
            else answer += '(';
        }
    }
    return answer;
}

int main() {
    string str = "(()))(";
    cout << solution(str);
    return 0;
}