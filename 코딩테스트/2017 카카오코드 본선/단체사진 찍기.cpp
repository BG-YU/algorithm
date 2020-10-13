/*
https://programmers.co.kr/learn/courses/30/lessons/1835
[문제 설명]
가을을 맞아 카카오프렌즈는 단체로 소풍을 떠났다.
즐거운 시간을 보내고 마지막에 단체사진을 찍기 위해 카메라 앞에 일렬로 나란히 섰다.
그런데 각자가 원하는 배치가 모두 달라 어떤 순서로 설지 정하는데 시간이 오래 걸렸다.
네오는 프로도와 나란히 서기를 원했고, 튜브가 뿜은 불을 맞은 적이 있던 라이언은 튜브에게서 적어도 세 칸 이상 떨어져서 서기를 원했다.
사진을 찍고 나서 돌아오는 길에, 무지는 모두가 원하는 조건을 만족하면서도 다르게 서는 방법이 있지 않았을까 생각해보게 되었다.
각 프렌즈가 원하는 조건을 입력으로 받았을 때 모든 조건을 만족할 수 있도록 서는 경우의 수를 계산하는 프로그램을 작성해보자.

[입력 형식]
입력은 조건의 개수를 나타내는 정수 n과 n개의 원소로 구성된 문자열 배열 data로 주어진다.
data의 원소는 각 프렌즈가 원하는 조건이 N~F=0과 같은 형태의 문자열로 구성되어 있다.
제한조건은 아래와 같다.
 - 1 <= n <= 100
 - data의 원소는 다섯 글자로 구성된 문자열이다. 각 원소의 조건은 다음과 같다.
 - 첫 번째 글자와 세 번째 글자는 다음 8개 중 하나이다. {A, C, F, J, M, N, R, T} 각각 어피치, 콘, 프로도, 제이지, 무지, 네오, 라이언, 튜브를 의미한다. 첫 번째 글자는 조건을 제시한 프렌즈, 세 번째 글자는 상대방이다. 첫 번째 글자와 세 번째 글자는 항상 다르다.
 - 두 번째 글자는 항상 ~이다.
 - 네 번째 글자는 다음 3개 중 하나이다. {=, <, >} 각각 같음, 미만, 초과를 의미한다.
 - 다섯 번째 글자는 0 이상 6 이하의 정수의 문자형이며, 조건에 제시되는 간격을 의미한다. 이때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수이다.

 [출력 형식]
모든 조건을 만족하는 경우의 수를 리턴한다.

[예제 입출력]
n   data            answer
2   [N~F=0, R~T>2]  3648
2   [M~C\<2, C~M>1] 0
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

char arr[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
int used[8] = { 0 };
int cnt = 0;
unordered_map<char, int> hm;

int fn_abs(int a) {
    return a < 0 ? -(a) : a;
}

int chk(char a, char b, int num, char sign) {
    int flag = 0;
    int ret = fn_abs(hm[a] - hm[b]);

    switch (sign) {
    case '=':
        if (ret - 1 == num) flag++;
        break;
    case '>':
        if (ret > num + 1) flag++;
        break;
    case '<':
        if (ret < num + 1) flag++;
        break;
    }

    return flag;
}

void dfs(int lv, vector<string> data) {
    if (lv == 8) {
        int flag = 0;
        for (int i = 0; i < data.size(); i++) {
            int ret = chk(data[i][0], data[i][2], (data[i][4] - '0'), data[i][3]);
            if (ret == 0) {
                flag = 0;
                break;
            }
            else flag = 1;
        }

        if (flag == 1) cnt++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (used[i] == 1) continue;
        used[i] = 1;
        hm[arr[i]] = lv + 1;
        dfs(lv + 1, data);
        used[i] = 0;
        hm[arr[i]] = -1;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    cnt = 0;
    dfs(0, data);
    answer = cnt;
    return answer;
}

int main() {
    vector<string> data = { "N~F=0","R~T>2" };
    solution(2, data);
    return 0;
}