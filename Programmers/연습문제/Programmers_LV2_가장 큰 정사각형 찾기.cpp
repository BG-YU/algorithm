/*
https://programmers.co.kr/learn/courses/30/lessons/12905
[문제 설명]
1와 0로 채워진 표(board)가 있습니다.
표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다.
표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요.
(단, 정사각형이란 축에 평행한 정사각형을 말합니다.)

예를 들어

1	2	3	4
0	1	1	1
1	1	1	1
1	1	1	1
0	0	1	0
가 있다면 가장 큰 정사각형은

1	2	3	4
0	1	1	1
1	1	1	1
1	1	1	1
0	0	1	0
가 되며 넓이는 9가 되므로 9를 반환해 주면 됩니다.

[제한사항]
 - 표(board)는 2차원 배열로 주어집니다.
 - 표(board)의 행(row)의 크기 : 1,000 이하의 자연수
 - 표(board)의 열(column)의 크기 : 1,000 이하의 자연수
 - 표(board)의 값은 1또는 0으로만 이루어져 있습니다.

[입출력 예]
board                                       answer
[[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]   9
[[0,0,1,1],[1,1,1,1]]                       4

입출력 예 설명
입출력 예 #1
위의 예시와 같습니다.

입출력 예 #2
| 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 |
로 가장 큰 정사각형의 넓이는 4가 되므로 4를 return합니다.
*/

/*
풀이
알고리즘 : DP
모르겠어서 구글링...
아직도 왜 좌상(좌측 대각선 위)과 좌, 우 중 가장 작은 값이랑 현재 대상의 값이랑 더하면 한변의 길이가 나오는지 이해가 잘 안감..

1. 좌상, 좌, 우 중 가장 작은 값을 구한다.
2. 현재 대상이 되는 값 항상 1
3. 1번에서 구한 min값과 1을 더한다.
4. 반복한다.
5. 반복 하면서 가장 큰수를 비교하여 찾아 둔다.
6. 가장큰수(한변의 길이)를 제곱한다.(넓이의 공식)

*/
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = board[0][0];

    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j] == 0) continue;

            board[i][j] = min(board[i][j - 1], board[i - 1][j]);
            board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
            answer = max(answer, board[i][j]);
        }
    }

    return answer * answer;
}

int main() {
    //[[0, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [0, 0, 1, 0]]
    vector<vector<int>> board;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(0);
    board.push_back(tmp);
    tmp.clear();

    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    board.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    board.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    board.push_back(tmp);
    tmp.clear();

    solution(board);
    return 0;
}