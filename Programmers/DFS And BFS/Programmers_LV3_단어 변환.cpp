/*
https://programmers.co.kr/learn/courses/30/lessons/43163
[문제 설명]
두 개의 단어 begin, target과 단어의 집합 words가 있습니다.
아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 hit, target가 cog, words가 [hot,dot,dog,lot,log,cog]라면 hit -> hot -> dot -> dog -> cog와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때,
최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

[제한사항]
 - 각 단어는 알파벳 소문자로만 이루어져 있습니다.
 - 각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
 - words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
 - begin과 target은 같지 않습니다.
 - 변환할 수 없는 경우에는 0를 return 합니다.

[입출력 예]
begin   target  words                           return
hit     cog     [hot, dot, dog, lot, log, cog]  4
hit     cog     [hot, dot, dog, lot, log]       0
*/

#include <string>
#include <vector>

using namespace std;

int cnt_min = 21e8;

int fn_chk(string begin, string cmp_str) {
    int cnt = 0;

    for (int i = 0; i < begin.length(); i++) {
        if (begin[i] == cmp_str[i]) cnt++;
    }

    return cnt;
}

void dfs(int lv, int limit, int cnt, string begin, string target, vector<int> used, vector<string> words) {
    int maxx = 0;
    int index = 0;

    if (lv == limit || begin == target) {
        if (cnt_min > cnt) cnt_min = cnt;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (used[i] == 1) continue;

        int num = fn_chk(begin, words[i]);
        int len = begin.length();

        if (len - num == 1) {
            if (words[i] == begin) {
                cnt_min = cnt + 1;
                return;
            }

            index = i;
        }

        if (len - num == 0) {
            cnt_min = cnt + 1;
            return;
        }
    }

    used[index] = 1;
    dfs(lv + 1, limit, cnt + 1, words[index], target, used, words);
    used[index] = 0;
}

int solution(string begin, string target, vector<string> words) {
    int flag = 0;
    vector<int> used(words.size(), 0);

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) return 0;

    dfs(0, words.size(), 0, begin, target, used, words);

    return cnt_min;
}

int main() {
    vector<string> words;
    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");
    words.push_back("cog");
    solution("hit","cog", words);
    return 0;
}