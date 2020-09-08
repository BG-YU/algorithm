/*
https://programmers.co.kr/learn/courses/30/lessons/1829
[카카오 프렌즈 컬러링북]
출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 
여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 그림의 난이도를 영역의 수로 정의하였다. 
(영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)

그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.

[입력 형식]
입력은 그림의 크기를 나타내는 m과 n, 그리고 그림을 나타내는 m × n 크기의 2차원 배열 picture로 주어진다. 제한조건은 아래와 같다.
 - 1 <= m, n <= 100
 - picture의 원소는 0 이상 2^31 - 1 이하의 임의의 값이다.
 - picture의 원소 중 값이 0인 경우는 색칠하지 않는 영역을 뜻한다.

 [출력 형식]
리턴 타입은 원소가 두 개인 정수 배열이다. 
그림에 몇 개의 영역이 있는지와 가장 큰 영역은 몇 칸으로 이루어져 있는지를 리턴한다.

[예제 입출력]
m   n   picture                                                                                 answer
6   4   [[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]    [4, 5]
예제에 대한 설명
예제로 주어진 그림은 총 4개의 영역으로 구성되어 있으며, 왼쪽 위의 영역과 오른쪽의 영역은 모두 1로 구성되어 있지만 상하좌우로 이어져있지 않으므로 다른 영역이다. 
가장 넓은 영역은 왼쪽 위 1이 차지하는 영역으로 총 5칸이다.
*/

#include <vector>

using namespace std;

vector<vector<int>> v_tmp;
struct node {
    int y, x;
};
node queue[100000];

int bfs(int num, int y, int x) {
    int direct[4][2] = {
        -1,0,
        0,-1,
        1,0,
        0,1
    };

    int head = 0;
    int tail = 0;
    int limit_y = v_tmp.size();
    int limit_x = v_tmp[0].size();
    int cnt = 1;

    queue[tail++] = { y, x };
    v_tmp[y][x] = 0;

    while (head != tail) {
        node now = queue[head++];

        for (int i = 0; i < 4; i++) {
            int dy = now.y + direct[i][0];
            int dx = now.x + direct[i][1];

            if (dy >= limit_y || dx >= limit_x || dy < 0 || dx < 0) continue;
            if (v_tmp[dy][dx] == 0) continue;
            if (v_tmp[dy][dx] != num) continue;
            v_tmp[dy][dx] = 0;
            cnt++;
            queue[tail++] = { dy,dx };
        }
    }

    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> tmp;
    v_tmp = picture;

    for (int i = 0; i < picture.size(); i++) {
        tmp = picture[i];
        for (int k = 0; k < tmp.size(); k++) {
            if (picture[i][k] == 0) continue;
            if (v_tmp[i][k] == 0) continue;
            int ret = bfs(picture[i][k], i, k);
            number_of_area++;
            if (max_size_of_one_area < ret) max_size_of_one_area = ret;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    vector<vector<int>> picture;
    vector<int> tmp;

    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    picture.push_back(tmp);
    tmp.clear();

    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(2);
    tmp.push_back(0);
    picture.push_back(tmp);
    tmp.clear();

    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(1);
    picture.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(1);
    picture.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(3);
    picture.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(3);
    picture.push_back(tmp);
    tmp.clear();

    solution(6, 4, picture);
    return 0;
}