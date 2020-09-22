/*
6칸짜리 두 배열이 있습니다.
두배열에 6자리 숫자를 각각 채워주세요.
그리고 두 숫자의 합을 출력 해주세요.
(두 수의 합이 1,000,000보다 작은 입력값으로 주어집니다.)
자릿수 올림 처리를 잊지마세요

ex)
351429 + 37735 = 489163

 351429
+137735
--------
 489163
*/

#include <iostream>
using namespace std;

int main() {
	int arr1[6], arr2[6], bucket[7] = {};
	int num;

	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 6; k++) {
			if (i == 0) {
				cin >> arr1[k];
			}
			else {
				cin >> arr2[k];
			}
		}
	}

	for (int i = 5; i >= 0; i--) {
		bucket[i + 1] = bucket[i + 1] + (arr1[i] + arr2[i]) % 10;
		bucket[i] = (arr1[i] + arr2[i]) / 10;
	}

	for (int i = 0; i < 7; i++) {
		if (i == 0 && bucket[i] == 0) continue;
		cout << bucket[i] << " ";
	}

	return 0;
}