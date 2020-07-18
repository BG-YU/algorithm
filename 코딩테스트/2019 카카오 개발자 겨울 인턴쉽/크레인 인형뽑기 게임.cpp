/*
카카오 2019 개발자 겨울 인턴쉽
크레인 인형뽑기 게임
https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> map = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> board[30];
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    vector<int> tong;
    int cnt = 0;

    for (int i = 0; i < map.size(); i++) {
        for (int k = map.size() - 1; k >= 0; k--) {
            if (map[k][i] == 0) continue;
            board[i].push_back(map[k][i]);
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        int temp = board[moves[i] - 1].size();
        if (temp <= 0) {
            if (tong.size() < 2) continue;
            if (tong[tong.size() - 1] == tong[tong.size() - 2]) {
                tong.pop_back();
                tong.pop_back();
                cnt += 2;
            }
            continue;
        }
        tong.push_back(board[moves[i] - 1][temp - 1]);
        board[moves[i] - 1].pop_back();

        if (tong.size() < 2) continue;
        if (tong[tong.size() - 1] == tong[tong.size() - 2]) {
            tong.pop_back();
            tong.pop_back();
            cnt+=2;
        }
    }

    cout << cnt;

    return 0;
}