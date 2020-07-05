#include <iostream>
#include <cstring>
using namespace std;

int arr[2001][2001];
int a, b, c, d, cnt = 0;
int used[2001];

void run(int now, int level) {
	if (level > 3) {
		cnt = 1;
		return;
	}
	for (int i = 0; i < a; i++) {
		if (arr[now][i] == 1) {
			if(used[i] == 0){
				used[i] = 1;
				run(i, level + 1);
				if (cnt == 1) return;
			}
		}
	}
}

int main() {
	cin >> a >> b;

	for (int i = 0; i < b; i++) {
		cin >> c >> d;
		arr[c][d] = 1;
		arr[d][c] = 1;
	}

	for (int i = 0; i < a; i++) {
		memset(used, -1, sizeof(used));
		cnt = 0;
		run(i, 0);
		if (cnt == 1) break;
	}
	
	cout << cnt;

	return 0;
}