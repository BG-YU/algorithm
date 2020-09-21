/*
https://programmers.co.kr/learn/courses/30/lessons/42579
[문제 설명]
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.
노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때,
베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

[제한사항]
 - genres[i]는 고유번호가 i인 노래의 장르입니다.
 - plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
 - genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
 - 장르 종류는 100개 미만입니다.
 - 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
 - 모든 장르는 재생된 횟수가 다릅니다.

[입출력 예]
genres                                  plays                       return
[classic, pop, classic, classic, pop]   [500, 600, 150, 800, 2500]  [4, 1, 3, 0]


[입출력 예 설명]
classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.

고유 번호 3: 800회 재생
고유 번호 0: 500회 재생
고유 번호 2: 150회 재생
pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.

고유 번호 4: 2,500회 재생
고유 번호 1: 600회 재생
따라서 pop 장르의 [4, 1]번 노래를 먼저, classic 장르의 [3, 0]번 노래를 그다음에 수록합니다.
*/

/*
풀이
1. 해쉬맵으로 장르별로 플레이횟수를 저장한다.
2. 만들어진 해쉬맵으로 장르별 플레이 횟수의 총합으로 내림차순 정렬한다.
3. 장르 안의 곡 하나하나의 플레이횟수기준으로 내림차순 정렬한다.
4. 장르 마다 2곡씩 뽑아서 결과값에 담는다.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
    int sum;
    vector<pair<int, int>> vect;
};

bool compare1(pair<string, node> a, pair<string, node> b) {
    if (a.second.sum > b.second.sum) return true;
    if (a.second.sum < b.second.sum) return false;
    return a.first < b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return true;
    if (a.second < b.second) return false;
    return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, node> um;
    vector<pair<string, node>> v_temp;
    vector<int> answer;

    // 해쉬맵 만들기
    for (int i = 0; i < genres.size(); i++) {
        um[genres[i]].sum += plays[i];
        um[genres[i]].vect.push_back(make_pair(i, plays[i]));
    }
    
    // 해쉬맵 정렬
    for (pair<string, node> elem : um) v_temp.push_back(elem);
    sort(v_temp.begin(), v_temp.end(), compare1);

    // 정렬된 해쉬맵을 다시 곡 기준으로 정렬
    // 정렬이 완료된 장르는 2곡을 뽑아 결과값에 저장
    for (int i = 0; i < v_temp.size(); i++) {
        sort(v_temp[i].second.vect.begin(), v_temp[i].second.vect.end(), compare2);

        int cnt = 0;
        for (int k = 0; k < v_temp[i].second.vect.size(); k++) {
            if (cnt >= 2) break;
            answer.push_back(v_temp[i].second.vect[cnt++].first);
        }
    }

    return answer;
}

int main() {
    vector<string> genres; 
    vector<int> plays;

    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");

    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);
    solution(genres, plays);

    return 0;
}