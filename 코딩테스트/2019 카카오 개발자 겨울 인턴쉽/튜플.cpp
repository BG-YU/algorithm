/*
카카오 2019 개발자 겨울 인턴쉽
튜플

https://programmers.co.kr/learn/courses/30/lessons/64065

s	result
"{{2},{2,1},{2,1,3},{2,1,3,4}}"	[2, 1, 3, 4]
"{{1,2,3},{2,1},{1,2,4,3},{2}}"	[2, 1, 3, 4]
"{{20,111},{111}}"	[111, 20]
"{{123}}"	[123]
"{{4,2,3},{3},{2,3,4,1},{2,3}}"	[3, 2, 4, 1]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[100000];

bool compare(int a, int b) {
    if (arr[a] > arr[b]) return true;
    if (arr[a] < arr[b]) return false;

    return false;
}

int main() {
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";

    vector<int> answer;
    vector<char> vect;

    string temp;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{') continue;
        
        temp += s[i];

        if (temp.length() == 1 && (temp == "," || temp == "}")) temp = "";

        if (temp.size() > 0 && (temp[temp.size() - 1] == ',' || temp[temp.size() - 1] == '}')) {
            if (temp[temp.size() - 1] == '}' || temp[temp.size() - 1] == ',') temp[temp.size() - 1] = '\0';
            if(arr[stoi(temp)] == 0) answer.push_back(stoi(temp));
            arr[stoi(temp)]++;
            temp = "";
        }
    }

    sort(answer.begin(), answer.end(), compare);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}