/*
https://programmers.co.kr/learn/courses/30/lessons/17681
비밀지도
네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다.
그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다.
다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다.

1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 공백(" ) 또는벽(#") 두 종류로 이루어져 있다.
2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 지도 1과 지도 2라고 하자. 
   지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다.
   지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
3. 지도 1과 지도 2는 각각 정수 배열로 암호화되어 있다.
4. 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열이다.

[지도1]
 #  #|01001 -> 9
# #  |10100 -> 20
###  |11100 -> 28
#  # |10010 -> 18
 # ##|01011 -> 11

[지도2]
#### |11110 -> 30
    #|00001 -> 1
# # #|10101 -> 21
#   #|10001 -> 17
###  |11100 -> 28

[지도1 + 지도2 = 비밀지도]
#####|
# # #|
### #|
#  ##|
#####|

네오가 프로도의 비상금을 손에 넣을 수 있도록, 비밀지도의 암호를 해독하는 작업을 도와줄 프로그램을 작성하라.

[입력 형식]
입력으로 지도의 한 변 크기 n 과 2개의 정수 배열 arr1, arr2가 들어온다.

1 ≦ n ≦ 16
arr1, arr2는 길이 n인 정수 배열로 주어진다.
정수 배열의 각 원소 x를 이진수로 변환했을 때의 길이는 n 이하이다. 즉, 0 ≦ x ≦ 2n - 1을 만족한다.
출력 형식
원래의 비밀지도를 해독하여 '#', 공백으로 구성된 문자열 배열로 출력하라.

[입출력 예제]
매개변수    값
n           5
arr1        [9, 20, 28, 18, 11]
arr2        [30, 1, 21, 17, 28]
출력        ["#####","# # #", "### #", "# ##", "#####"]

매개변수    값
n           6
arr1        [46, 33, 33 ,22, 31, 50]
arr2        [27 ,56, 19, 14, 14, 10]
출력        ["######", "### #", "## ##", " #### ", " #####", "### # "]
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string b_str = "";
int maxx = -21e8;

void binary_num(int a) {
    int num = 0;
    if (a <= 0) return;
    num = a % 2;
    a /= 2;
    binary_num(a);
    b_str += num + '0';
    return;
}

vector<string> set_map(vector<int> arr) {
    vector<string> vect;
    vector<int> tmp = arr;
    int cnt = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    binary_num(arr[0]);
    maxx = b_str.length();
    b_str = "";

    for (int i = 0; i < tmp.size(); i++) {
        binary_num(tmp[i]);
        cnt = b_str.length();

        if (cnt < maxx) {
            for (int k = 0; k < maxx - cnt; k++) {
                b_str.insert(0, "0");
            }
        }

        vect.push_back(b_str);
        b_str = "";
    }

    return vect;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> tmp1, tmp2;
    string tmp = "";

    tmp1 = set_map(arr1);
    tmp2 = set_map(arr2);

    for (int i = 0; i < tmp1.size(); i++) {
        for (int k = 0; k < tmp1[i].length(); k++) {
            if (tmp1[i][k] == '1' || tmp2[i][k] == '1') tmp += '#';
            else tmp += ' ';
        }
        answer.push_back(tmp);
        tmp = "";
    }

    return answer;
}