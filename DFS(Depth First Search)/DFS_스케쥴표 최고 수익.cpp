/*
상담 업무를 할 수 있는 스케쥴 표가 주어집니다.

	      1일 2일 3일 4일 5일
   소요일  3   5   1   1   2
받는 수익 10  20  10  20  15

만약 1일 업무를 맡게 된다면 1,2,3일은 상담 업무를 하게 되고, 10만원을 벌 수 있습니다.
그리고 4일 업무를 맡지 않고 5일 업무를 맡게 된다면 5일, 6일에 상담 업무를 할 수 있고
총 10 + 15 = 25만원을 벌 수 있습니다.
위 스케쥴 표에서는 1일, 4일, 5일에서 일을 하면 최대 45만원을 벌 수 있습니다.

[예시]
아래 예제에서는 2일, 5일 일을 하면 최대 60만원을 벌 수 있습니다.

		  1일 2일 3일 4일 5일
   소요일  2   2   1   2   1
받는 수익 20  30   5  10  30

[입력]
스케쥴 날짜의 개수 N이 입력됩니다.
다음 줄에, 상담 소요일과 받는 수익이 입력 됩니다.

[출력]
상담 스케쥴을 조정하여 가장 수익을 많이 벌 수 있는 금액을 출력하세요.

[입력 예제]
5
3 10
5 20
1 10
1 20
2 15

[출력 결과]
45
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> work;
int arr[100];
char ox[2] = { 'O','X' };
int maxx, sum;
int num, n1, n2;
void dfs(int lv, int sum) {
	if (lv == num) {
		if (maxx < sum) maxx = sum;
		return;
	}
	
	for (int i = 0; i < 2; i++) {
		if ((lv > 0 && arr[lv] == 1) || ox[i] == 'X') {
			dfs(lv + 1, sum);
		}
		else {
			for (int k = 0; k < work[lv].first; k++) arr[lv + k] = 1;
			dfs(lv + 1, sum + work[lv].second);
			for (int k = 0; k < work[lv].first; k++) arr[lv + k] = 0;
		}
	}

	return;
}

int main() {
	cin >> num;

	for (int i = 0; i < num; i++){
		cin >> n1 >> n2;
		work.push_back({n1, n2});
	}

	dfs(0, 0);

	cout << maxx;
	return 0;
}