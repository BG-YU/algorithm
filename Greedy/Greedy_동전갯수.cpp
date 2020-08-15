/*
입력받은 거슴름돈을 돌려 줄대 최소의 동전 갯수는?

동전
500 100 50 10
*/

#include <iostream>
using namespace std;

int main() {
	int num, cnt = 0;
	int arr[4] = { 500, 100, 50, 10 };
	cin >> num;

	while (1) {
		if (num <= 0) break;

		for (int i = 0; i < 4; i++) {
			if (num >= arr[i]) {
				num -= arr[i];
				break;
			}
		}
		cnt++;
	}

	cout << cnt;
	return 0;
}

/*
// [DFS 풀이]
#include <iostream>
using namespace std;

int arr[4] = {500,100,50,10};
int minn = 21e8;

void dfs(int num, int cnt) {
	if (num <= 0) {
		if (minn > cnt) minn = cnt;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (num < arr[i]) continue;
		dfs(num - arr[i], cnt + 1);
	}
}

int main() {
	int num;
	cin >> num;
	dfs(num, 0);
	cout << minn;
	return 0;
}
*/