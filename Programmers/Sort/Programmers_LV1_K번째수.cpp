/*
https://programmers.co.kr/learn/courses/30/lessons/42748
[문제 설명]
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면

array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
2에서 나온 배열의 3번째 숫자는 5입니다.
배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
array의 길이는 1 이상 100 이하입니다.
array의 각 원소는 1 이상 100 이하입니다.
commands의 길이는 1 이상 50 이하입니다.
commands의 각 원소는 길이가 3입니다.

[입출력 예]
array	commands	return
[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]

[입출력 예 설명]
[1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
[1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
[1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.
*/
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for (int i = 0; i < commands.size(); i++) {
        for (int k = commands[i][0] - 1; k < commands[i][1]; k++) {
            tmp.push_back(array[k]);
        }

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
        tmp.clear();
    }

    return answer;
}

int main() {
    //[1, 5, 2, 6, 3, 7, 4] [[2, 5, 3], [4, 4, 1], [1, 7, 3]] [5, 6, 3]
    vector<int> tmp1, tmp2, ret; 
    vector<vector<int>> tmp3;

    tmp1.push_back(1);
    tmp1.push_back(5);
    tmp1.push_back(2);
    tmp1.push_back(6);
    tmp1.push_back(3);
    tmp1.push_back(7);
    tmp1.push_back(4);


    tmp2.push_back(2);
    tmp2.push_back(5);
    tmp2.push_back(3);
    tmp3.push_back(tmp2);
    tmp2.clear();

    tmp2.push_back(4);
    tmp2.push_back(4);
    tmp2.push_back(1);
    tmp3.push_back(tmp2);
    tmp2.clear();

    tmp2.push_back(1);
    tmp2.push_back(7);
    tmp2.push_back(3);
    tmp3.push_back(tmp2);
    
    ret = solution(tmp1, tmp3);

    for (int i = 0; i < ret.size(); i++) cout << ret[i];

    return 0;
}