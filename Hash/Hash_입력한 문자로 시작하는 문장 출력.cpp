/*
A를 입력하면
A로 시작 하는 모든 문장
AT를 입력 하면 AT로 시작하는 모든 문장
출력 하기
*/

#include<iostream>
#include<string> 
#include<unordered_map>

using namespace std;
unordered_multimap<string, string>a;

string arr[6] = {
	"ATSBCD",
	"ABSBT",
	"ATC",
	"ATST",
	"ABBQQ",
	"ATSS"
};
void sett() {
	for (int x = 0; x < 6; x++) {
		int n = arr[x].length();  // 길이

		for (int y = 0; y <= n; y++) {
			string temp = arr[x].substr(0, y);   // 첨부터 길이까지 추출
			a.insert({ temp,arr[x] });  // 추출한부분 키값 등록
		}
	}
}
int main() {
	sett(); // 해쉬에 등록

	string target;
	cin >> target;

	cout << a.count(target) << endl;

	for (auto x = a.find(target); x != a.end(); x++) {
		if (x->first != target)break;
		cout << x->second << endl;
	}

	return 0;
}