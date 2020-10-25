/*
https://programmers.co.kr/learn/courses/30/lessons/67256
문제 설명
스마트폰 전화 키패드의 각 칸에 다음과 같이 숫자들이 적혀 있습니다.

123
456
789
*0#

이 전화 키패드에서 왼손과 오른손의 엄지손가락만을 이용해서 숫자만을 입력하려고 합니다.
맨 처음 왼손 엄지손가락은 * 키패드에 오른손 엄지손가락은 # 키패드 위치에서 시작하며, 엄지손가락을 사용하는 규칙은 다음과 같습니다.

엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당합니다.
왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용합니다.
오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용합니다.
가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용합니다.
4-1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용합니다.
순서대로 누를 번호가 담긴 배열 numbers, 왼손잡이인지 오른손잡이인 지를 나타내는 문자열 hand가 매개변수로 주어질 때, 각 번호를 누른 엄지손가락이 왼손인 지 오른손인 지를 나타내는 연속된 문자열 형태로 return 하도록 solution 함수를 완성해주세요.

[제한사항]
numbers 배열의 크기는 1 이상 1,000 이하입니다.
numbers 배열 원소의 값은 0 이상 9 이하인 정수입니다.
hand는 "left" 또는 "right" 입니다.
"left"는 왼손잡이, "right"는 오른손잡이를 의미합니다.
왼손 엄지손가락을 사용한 경우는 L, 오른손 엄지손가락을 사용한 경우는 R을 순서대로 이어붙여 문자열 형태로 return 해주세요.

[입출력 예]
numbers	hand	result
[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]	"right"	"LRLLLRLLRRL"
[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]	"left"	"LRLLRRLLLRR"
[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]	"right"	"LLRLLRLLRL"
입출력 예에 대한 설명
입출력 예 #1

순서대로 눌러야 할 번호가 [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]이고, 오른손잡이입니다.

왼손 위치	오른손 위치	눌러야 할 숫자	사용한 손	설명
*	#	1	L	1은 왼손으로 누릅니다.
1	#	3	R	3은 오른손으로 누릅니다.
1	3	4	L	4는 왼손으로 누릅니다.
4	3	5	L	왼손 거리는 1, 오른손 거리는 2이므로 왼손으로 5를 누릅니다.
5	3	8	L	왼손 거리는 1, 오른손 거리는 3이므로 왼손으로 8을 누릅니다.
8	3	2	R	왼손 거리는 2, 오른손 거리는 1이므로 오른손으로 2를 누릅니다.
8	2	1	L	1은 왼손으로 누릅니다.
1	2	4	L	4는 왼손으로 누릅니다.
4	2	5	R	왼손 거리와 오른손 거리가 1로 같으므로, 오른손으로 5를 누릅니다.
4	5	9	R	9는 오른손으로 누릅니다.
4	9	5	L	왼손 거리는 1, 오른손 거리는 2이므로 왼손으로 5를 누릅니다.
5	9	-	-
따라서 "LRLLLRLLRRL"를 return 합니다.

입출력 예 #2
왼손잡이가 [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]를 순서대로 누르면 사용한 손은 "LRLLRRLLLRR"이 됩니다.

입출력 예 #3
오른손잡이가 [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]를 순서대로 누르면 사용한 손은 "LLRLLRLLRL"이 됩니다.
*/

#include <string>
#include <vector>

using namespace std;

struct node {
    int num;
    string hand;
};
node pad[4][3] = {
    {{1, "L"},{2, ""},{3, "R"}},
    {{4, "L"},{5, ""},{6, "R"}},
    {{7, "L"},{8, ""},{9, "R"}},
    {{-1, ""},{0, ""},{-1, ""}}
};

int bfs(int target, int y, int x) {
    struct n {
        int y, x, lv;
    };

    int visit[4][3] = {
        0,0,0,
        0,0,0,
        0,0,0,
        0,0,0
    };

    int direct[4][2] = {
        -1,0,
        0,-1,
        1,0,
        0,1
    };

    int ret = 0;
    int head = 0;
    int tail = 0;

    n queue[100];
    queue[tail++] = { y,x,0 };
    visit[y][x] = 1;


    while (head != tail) {
        n now = queue[head++];

        for (int i = 0; i < 4; i++) {
            int dy = direct[i][0] + now.y;
            int dx = direct[i][1] + now.x;

            if (dy < 0 || dx < 0 || dy > 3 || dx > 2) continue;
            if (visit[dy][dx] == 1) continue;
            if (pad[dy][dx].num == -1) continue;
            visit[dy][dx] = 1;

            queue[tail++] = { dy,dx, now.lv + 1 };
            if (pad[dy][dx].num == target) {
                ret = queue[tail - 1].lv;
                break;
            }
        }
    }

    return ret;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int y, x;
    int l_now_y = 3, l_now_x = 0, r_now_y = 3, r_now_x = 2;
    struct num {
        int num, y, x;
    };

    pair<int, int> p_arr[10];
    p_arr[0] = { 3,1 };
    p_arr[1] = { 0,0 };
    p_arr[2] = { 0,1 };
    p_arr[3] = { 0,2 };
    p_arr[4] = { 1,0 };
    p_arr[5] = { 1,1 };
    p_arr[6] = { 1,2 };
    p_arr[7] = { 2,0 };
    p_arr[8] = { 2,1 };
    p_arr[9] = { 2,2 };

    for (int i = 0; i < numbers.size(); i++) {
        y = p_arr[numbers[i]].first;
        x = p_arr[numbers[i]].second;

        if (pad[y][x].hand == "") {
            int a = bfs(pad[y][x].num, l_now_y, l_now_x);
            int b = bfs(pad[y][x].num, r_now_y, r_now_x);

            if (a == b) {
                if (hand == "left") {
                    answer += "L";
                    l_now_y = p_arr[pad[y][x].num].first;
                    l_now_x = p_arr[pad[y][x].num].second;
                }
                if (hand == "right") {
                    answer += "R";
                    r_now_y = p_arr[pad[y][x].num].first;
                    r_now_x = p_arr[pad[y][x].num].second;
                };
            }
            else {
                if (a < b) {
                    answer += "L";
                    l_now_y = p_arr[pad[y][x].num].first;
                    l_now_x = p_arr[pad[y][x].num].second;
                }
                else {
                    answer += "R";
                    r_now_y = p_arr[pad[y][x].num].first;
                    r_now_x = p_arr[pad[y][x].num].second;
                }
            }
            continue;
        }

        if (pad[y][x].num == 1 || pad[y][x].num == 4 || pad[y][x].num == 7) {
            l_now_y = p_arr[pad[y][x].num].first;
            l_now_x = p_arr[pad[y][x].num].second;
        }

        if (pad[y][x].num == 3 || pad[y][x].num == 6 || pad[y][x].num == 9) {
            r_now_y = p_arr[pad[y][x].num].first;
            r_now_x = p_arr[pad[y][x].num].second;
        }

        answer += pad[y][x].hand;
    }

    return answer;
}

int main() {
    vector<int> numbers = {1,3,4,5,8,2,1,4,5,9,5};
    solution(numbers, "right");
    return 0;
}