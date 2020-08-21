/*
https://programmers.co.kr/learn/courses/30/lessons/42840
문제 설명
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

[입출력 예]
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]

[입출력 예 설명]
입출력 예 #1

수포자 1은 모든 문제를 맞혔습니다.
수포자 2는 모든 문제를 틀렸습니다.
수포자 3은 모든 문제를 틀렸습니다.
따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

[입출력 예 #2]

모든 사람이 2문제씩을 맞췄습니다.
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return true;
    if (a.second < b.second) return false;

    return a.first < b.first;
}

bool fn_cmp(int a, int b) {
    if (a == b) return true;
    else return false;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> tmp;

    tmp.push_back({ 1,0 });
    tmp.push_back({ 2,0 });
    tmp.push_back({ 3,0 });

    int arr1[5] = { 1,2,3,4,5 };
    int arr2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int arr3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == arr1[cnt1++]) tmp[0].second++;
        if (answers[i] == arr2[cnt2++]) tmp[1].second++;
        if (answers[i] == arr3[cnt3++]) tmp[2].second++;
        if (cnt1 > 4) cnt1 = 0;
        if (cnt2 > 7) cnt2 = 0;
        if (cnt3 > 9) cnt3 = 0;
    }

    sort(tmp.begin(), tmp.end(), compare);


    for (int i = 0; i < tmp.size(); i++) {
        if(answer.empty() || (i > 0 && fn_cmp(tmp[0].second, tmp[i].second))) answer.push_back(tmp[i].first);
    }

    return answer;
}

int main() {
    vector<int> vect, tmp;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    tmp = solution(vect);

    for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << endl;

    return 0;
}