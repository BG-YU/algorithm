/*
2020 KAKAO BLIND RECRUITMENT
자물쇠와 열쇠
https://programmers.co.kr/learn/courses/30/lessons/60059
*/

#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    return answer;
}

int main() {
    vector<vector<int>> key = {
        {0,0,0},
        {1,0,0},
        {0,1,1}
    };

    vector<vector<int>> lock = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    solution(key, lock);
    return 0;
}