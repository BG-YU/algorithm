/*
https://programmers.co.kr/learn/courses/30/lessons/43165
[문제 설명]
n개의 음이 아닌 정수가 있습니다.
이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다.
예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

[제한사항]
 - 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
 - 각 숫자는 1 이상 50 이하인 자연수입니다.
 - 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

[입출력 예]
numbers         target  return
[1, 1, 1, 1, 1] 3       5
*/

/*
[풀이]
왼쪽은 -
오른쪽은 +
를 가지는 2진트리로 생각하고 DFS를 돌린다.
깊이 탐색 횟수는 숫자의 갯수 만큼
*/

#include <string>
#include <vector>

using namespace std;

vector<int> t_num;
char arr[2] = { '-','+' };
int cnt = 0;

void dfs(int lv, int sum, int limit, int target) {
    if (lv == limit) {
        if (sum == target) cnt++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        switch (arr[i]) {
        case '-':
            dfs(lv + 1, sum - t_num[lv], limit, target);
            break;
        case '+':
            dfs(lv + 1, sum + t_num[lv], limit, target);
            break;
        }
    }
}

int solution(vector<int> numbers, int target) {
    t_num = numbers;
    dfs(0, 0, numbers.size(), target);
    return cnt;
}

int main() {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);

    solution(numbers, 3);
    return 0;
}