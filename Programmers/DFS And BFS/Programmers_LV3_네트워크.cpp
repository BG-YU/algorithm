/*
https://programmers.co.kr/learn/courses/30/lessons/43162
[문제 설명]
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다.
예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고,
컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다.
따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때,
네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

[제한사항]
컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
computer[i][i]는 항상 1입니다.

[입출력 예]
n   computers                           return
3   [[1, 1, 0], [1, 1, 0], [0, 0, 1]]   2
3   [[1, 1, 0], [1, 1, 1], [0, 1, 1]]   1
*/

/*
[풀이]
DFS로 진입한곳을 두번째에는 돌지 못하도록 0으로 바꾸고
한번의 DFS가 끝이 나면 하나의 네트워크 망이 있다고 간주한다.

1. DFS
2. DFS 진행 과정에서 숫자 1인것을 0으로 바꾸어 두번째 부터는 진입을 못하게 막는다.
3. computers를 2중 For문으로 돌려서 원소 하나하나 DFS를 돌린다.
   2번 과정에서 한번 지나 갔던 길은 0을 만들었기 때문에 두번째 부터는 돌지 않는다.
4. DFS가 끝이 날때 마다 answer++ 한다.
*/
#include <string>
#include <vector>

using namespace std;

void dfs(int lv, int now, int prev, int limit, vector<vector<int>>& computers) {
    if (lv == limit) {
        return;
    }

    for (int i = 0; i < computers[now].size(); i++) {
        if (computers[now][i] == 0) continue;
        computers[now][i] = 0;
        if (now == i) continue;
        if (prev == i) continue;
        dfs(lv + 1, i, now, limit, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (computers[i][k] == 1) {
                dfs(0, i, n, -1, computers);
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> computers;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(0);
    computers.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(0);
    computers.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(1);
    computers.push_back(temp);
    temp.clear();

    solution(3, computers);
    return 0;
}