/*
메뉴의 5개 음료 중에 N 개를 골라 얻을 수 있는 최대의 포인트는 몇 점인지 출력 해주세요.

아메리카노 500원 / 30point
수박쉐이크 700원 / 10point
초코쉐이크 600원 / 30point
멜론주스   300원 / 40point
카페라떼   400원 / 20point

위 메뉴에서 5개의 음료 중 N 개를 골라, 10,000원 어치 구매하려고 합니다.
N 개를 항상 같은 수량으로 최대한 구매해야 한다면 얻을 수 있는 MAX 포인트는 얼마일까요?


[예시]
예를들어 만약 n = 2 이고,
아메리카노 (500원, 30p) 수박 쉐이크 (700원, 10p) 를 선택하면
1,200원 x 8 = 9,600원으로 10,000원 안쪽으로 구매할 수 있습니다.
그리고 이 메뉴들의 총 포인트는 40p x 8 = 320pt 입니다.

[입력]
메뉴에서 골라야하는 음료의 개수 N 을 입력 해주세요.

[출력]
10,000 원 어치 최대로 구매 후, 얻을 수 있는 최대의 포인트 값을 출력 해주세요.


[입력 예제]
4
[출력 결과]
600
*/
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vect;
int arr[5];
int num, maxx = -21e8;

int fn_calc() {
	int sum_price = 0;
	int sum_point = 0;
	for (int i = 0; i < num; i++) {
		sum_price += vect[arr[i]].first;
		sum_point += vect[arr[i]].second;
	}
	return (10000 / sum_price) * sum_point;
}

void dfs(int lv, int st) {
	if (lv == num) {
		int ret = fn_calc();
		if (maxx < ret) maxx = ret;
		return;
	}

	for (int i = st; i < vect.size(); i++) {
		arr[lv] = i;
		dfs(lv + 1, i + 1);
	}
}

void init() {
	vect.push_back({ 500, 30 });
	vect.push_back({ 700, 10 });
	vect.push_back({ 600, 30 });
	vect.push_back({ 300, 40 });
	vect.push_back({ 400, 20 });
}

int main() {
	init();
	cin >> num;
	dfs(0, 0);
	cout << maxx;
	return 0;
}