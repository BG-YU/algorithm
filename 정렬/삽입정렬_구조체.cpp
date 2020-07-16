/*
숫자와 문자가 한 쌍인 n개 Set을 구조체배열에 입력받으세요. (1 <= n <= 100)
우선순위에 맞춰 삽입정렬로 정렬 후 출력하면 됩니다.

[우선순위]
1. 작은 숫자가 더 앞에 있어야 하며 (오름차순)
2. 같은 숫자인 경우, 더 작은 문자가 앞에 배치되어야 합니다.

정렬 전
{4 T} {4 F}	{5 E} {5 F} {4 A} {1 C}
정렬 후
{1 C} {4 A} {4 F} {4 T} {5 E} {5 F}
*/

#include <iostream>
using namespace std;

struct node {
	int num;
	char chr;
};

node arr[100];
node temp[100];

int compare(node n1, node n2) {
	if (n1.num > n2.num) return 0;
	if (n1.num < n2.num) return 1;

	return n1.chr < n2.chr;
}

int main() {
	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> arr[i].num >> arr[i].chr;
	}

	for (int i = 0; i < num; i++) {
		temp[i] = arr[i];
		for (int k = i; k > 0; k--) {
			if (compare(temp[k - 1], temp[k]) == 0) {
				swap(temp[k - 1], temp[k]);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		cout << temp[i].num << " " << temp[i].chr << endl;
	}

	return 0;
}