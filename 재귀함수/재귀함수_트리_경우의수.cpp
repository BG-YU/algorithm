/*
1 ~ n 명의 친구가 4일치 청소당번 순서를 정하려고 합니다.
첫번째 친구가 4일치 모두 청소할 수도 있고, 다양한 경우가 발생합니다.

ex) n = 3명일때 가능한 청소스케쥴
1111 / 1112 / 1113 / 1121 / 1122 / ... / 3332 / 3333

n명에 대해, 4일 동안의 청소스케줄을 모두 출력하는 프로그램을 작성해주세요
*/

#include <iostream>
using namespace std;

int cnt;
int path[10];

void run(int lv){
	if(lv == 4){
		for(int i = 0; i < lv; i++){
			cout << path[i];	
		}
		cout << endl;
		return;
	}
	
	for(int i = 1; i <= cnt; i++){
		path[lv] = i;
		run(lv + 1);
		path[lv] = 0;
	}
}

int main(){
	cin >> cnt;
	run(0);
	return 0;
}