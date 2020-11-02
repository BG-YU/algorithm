/*
https://programmers.co.kr/learn/courses/30/lessons/12981
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> um;
    for (int i = 0; i < words.size(); i++) {
        if (um.count(words[i]) > 0 || (i != 0 && words[i - 1][words[i - 1].length() - 1] != words[i][0])) {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
        else um[words[i]]++;
    }

    if (answer.empty()) answer = { 0,0 };

    return answer;
}

int main() {
    vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    solution(2, words);
    return 0;
}