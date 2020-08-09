/*
스타트 지점에서 출발한 승용차는 한칸씩 이동 가능하며
이동 할때 마다 좌표에 쓰여진 값만큼 기름을 사용한다.
최소의 기름을 사용하여 도착지점까지 갈때
그 최소의 기름의 양은 얼마나 되는가?

스타트 : (0,0)
엔드 : (4,4)
이동범위 : 위, 아래, 좌, 우

[행렬]
01712
42643
54522
18351
61210
*/
#include<iostream>
using namespace std;
enum {
	Right, Down
};
struct node {
	int dir, acc;
};
node vect[5][5];
int map[5][5] = {
	0,1,7,1,2,
	4,2,6,4,3,
	5,4,5,2,2,
	1,8,3,5,1,
	6,1,2,1,0
};
void sett(){
	for (int x = 0; x < 4; x++){
		vect[x][4].dir = Down;
		vect[4][x].dir = Right;

	}
	for (int x = 3; x >= 0; x--){
		vect[x][4].acc = vect[x + 1][4].acc + map[x][4];
		vect[4][x].acc = vect[4][x + 1].acc + map[4][x];
	}
}
int main(){
	sett();
	int y, x;
	for (y = 3; y >= 0; y--){
		for (x = 3; x >= 0; x--){
			int downacc = vect[y + 1][x].acc;
			int rightacc = vect[y][x + 1].acc;
			int ddang, sellectedacc;

			if (downacc < rightacc){
				ddang = Down;
				sellectedacc = rightacc;
			}
			else{
				ddang = Right;
				sellectedacc = rightacc;
			}

			vect[y][x].dir = ddang;
			vect[y][x].acc = sellectedacc + map[y][x];
		}
	}

	cout << vect[0][0].acc;
	return 0;
}