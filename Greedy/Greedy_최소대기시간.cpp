/*
화장실이 하나이기 때문에 화장실을 사용하려면 대기를 해야합니다.
기다리는 사람들이 모두 화장실을 사용한다고 할때, 총 대기시간이 적은 사용 순서를 정해주세요.

예를들어 총 네 명, A ~ D 사람이 화장실을 사용하는 시간이 다음과 같습니다.

A : 15
B : 30
C : 50
D : 10


한 사람이 화장실을 이용할 때 다른 사람들은 그 사람이 나오길 기다립니다.
사람들의 전체 대기시간이 최소가 되도록 사용순서를 정하고, 최소 대기시간을 출력해주세요.

[입력]
네 사람의 대기 시간을 입력 하세요.

[출력]
화장실을 모든 사람들이 사용완료 했을때 모든 사람이 대기해야하는 총 대기시간 들중, 최소 대기 시간을 출력하세요.
*/

// GREEDY 풀이
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vect;
	string str, tmp;
	int cnt = 0, sum = 0;
	getline(cin, str);

	while (1) {
		int index = str.find(' ', cnt);
		if (index == -1) {
			tmp = str.substr(cnt, str.length() - cnt);
			vect.push_back(stoi(tmp));
			break;
		}
		tmp = str.substr(cnt, index - cnt);
		vect.push_back(stoi(tmp));
		cnt = index + 1;
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < vect.size(); i++) {
		sum += vect[i] * ((vect.size() - 1) - i);
	}

	cout << sum;

	return 0;
}


/*
// [DFS 풀이]
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minn = 21e8;
vector<int> used;
vector<int> vect;

void dfs(int lv, int sum) {
	if (lv == 4) {
		if (sum < minn) minn = sum;
		return;
	}

	for (int i = 1; i < vect.size(); i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(lv + 1, sum + (vect[i] * ((vect.size() - 1) - lv)));
		used[i] = 0;
	}

	return;
}

int main() {
	string str, tmp;
	int cnt1 = 0, cnt2 = 0;;
	vect.push_back(1);
	used.push_back(0);
	getline(cin, str);

	while (1) {
		int index = str.find(' ', cnt1);
		if (index == -1) {
			vect.push_back(stoi(str.substr(cnt1, str.length())));
			used.push_back(0);
			break;
		}
		tmp = str.substr(cnt1, index - cnt1);
		vect.push_back(stoi(tmp));
		used.push_back(0);
		cnt1 = index + 1;
	}
	dfs(1, 0);
	cout << minn;
	return 0;
}
*/