/*
https://programmers.co.kr/learn/courses/30/lessons/42839
[문제 설명]
한자리 숫자가 적힌 종이 조각이 흩어져있습니다.
흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

[제한사항]
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

[입출력 예]
numbers return
17      3
011     2

[입출력 예 설명]
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
11과 011은 같은 숫자로 취급합니다.
*/

/*
풀이
1. 입력받은 문자열로 만들수 있는 숫자를 모두 구한다.
2. 입력받은 문자열로 구성 할수 있는 가장 큰수 까지 에라토스테네스의 체로 소수를 미리 구해 놓는다.
3. 입력받은 문자열로 구성 된 숫자들을 소수 판별한다.
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> used;
unordered_map<int, int> ret;
char chr[7];
int arr[1000000] = {0};
int maxx = 0;

void dfs(string numbers, int lv) {
    if (lv == numbers.length()) return;

    for (int i = 0; i < numbers.length(); i++) {
        if (used[i] > 0) continue;
        used[i]++;
        chr[lv] = numbers[i];
        string tmp(chr);
        int t_num = stoi(tmp);
        if (t_num != 1 && t_num != 0) {
            ret[t_num]++; // 만들어진 숫자 저장
            if (maxx < t_num) maxx = t_num; // MAX값 저장
        }
        dfs(numbers, lv + 1);
        used[i]--;
        chr[lv] = '\0';
    }
}

int solution(string numbers) {
    int answer = 0;
   
    dfs(numbers, 0);// 입력받은 숫자로 만들수 있는 모든수 만들기

    // 에라토스테네스의 체로 소수 구해놓기
    // (소수의 배수는 소수가 아니다)
    for (int i = 2; i <= sqrt(maxx); i++) {
        if (to_string(i).length() > numbers.length()) break;
        int tmp = i;
        while (1) {
            tmp += i;
            if (tmp > maxx) break;
            if (arr[tmp] == 1) continue;
            arr[tmp] = 1;
        }
    }

    // 만들어진 숫자들로 소수 판별
    for (pair<int, int> elem : ret) {
        if (arr[elem.first] == 0) answer++;
    }

    return answer;
}

int main() {
    solution("011");
    return 0;
}