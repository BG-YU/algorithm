/*
https://programmers.co.kr/learn/courses/30/lessons/17679
*/
#include <string>
#include <vector>

using namespace std;

int set_game(int m, int n, vector<string> &board) {
    int cnt = 0;
    int direct[4][2] = {
        0,0,
        0,1,
        1,0,
        1,1
    };

    vector<vector<int>> tmp(m, vector<int>(n, 0));

    for (int i = 0; i < m - 1; i++) {
        for (int k = 0; k < n - 1; k++) {
            char chr = board[i][k];
            if (chr == '0') continue;

            if (board[i][k] == chr && board[i + 1][k] == chr && board[i][k + 1] == chr && board[i + 1][k + 1] == chr) {
                for (int t = 0; t < 4; t++) {
                    int dy = i + direct[t][0];
                    int dx = k + direct[t][1];

                    if (board[dy][dx] == chr) {
                        tmp[dy][dx]++;
                        if (tmp[dy][dx] == 1) cnt++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tmp[i][j] > 0) {
                for (int k = i - 1; k >= 0; k--) {
                    board[k + 1][j] = board[k][j];
                    board[k][j] = '0';
                }
            }
        }
    }

    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        int ret = set_game(m, n, board);
        if (ret == 0) break;
        else answer += ret;
    }

    return answer;
}

int main() {
    vector<string> board = {
        "CCBDE",
        "AAADE",
        "AAABF",
        "CCBBF"
    };
    solution(4, 5, board);
    return 0;
}