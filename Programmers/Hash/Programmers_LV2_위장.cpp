/*
https://programmers.co.kr/learn/courses/30/lessons/42578
[문제 설명]
스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.
예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면
다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

종류	이름
얼굴	동그란 안경, 검정 선글라스
상의	파란색 티셔츠
하의	청바지
겉옷	긴 코트
스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성해주세요.

[제한사항]
 - lothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.
 - 스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.
 - 같은 이름을 가진 의상은 존재하지 않습니다.
 - clothes의 모든 원소는 문자열로 이루어져 있습니다.
 - 모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.
 - 스파이는 하루에 최소 한 개의 의상은 입습니다.

[입출력 예]
clothes                                                                         return
[[yellow_hat, headgear], [blue_sunglasses, eyewear], [green_turban, headgear]]  5
[[crow_mask, face], [blue_sunglasses, face], [smoky_makeup, face]]              3

[입출력 예 설명]
예제 #1
headgear에 해당하는 의상이 yellow_hat, green_turban이고 eyewear에 해당하는 의상이 blue_sunglasses이므로 아래와 같이 5개의 조합이 가능합니다.
1. yellow_hat
2. blue_sunglasses
3. green_turban
4. yellow_hat + blue_sunglasses
5. green_turban + blue_sunglasses

예제 #2
face에 해당하는 의상이 crow_mask, blue_sunglasses, smoky_makeup이므로 아래와 같이 3개의 조합이 가능합니다.
1. crow_mask
2. blue_sunglasses
3. smoky_makeup
*/

/*
[풀이]
입는 경우와 입지 않는 경우 둘로 나눌수 있다.
예를 들어 상의에 파란옷, 노란옷이 있다고 칠때
입을수 있는 경우의 수는 아래 세가지와 같다.
파란옷을 입을때
노란옷을 입을때
상의를 입지 않을때

그렇다면 경우의 수를 구할때
얼굴 : 동그란 안경, 검정 선글라스, 아무것도 하지 않음
상의 : 파란색 티셔츠, 아무것도 하지 않음
하의 : 청바지, 아무것도 하지 않음
겉옷 : 긴 코트, 아무것도 하지 않음
요렇게 나누어 지며, 위 얼굴, 상의, 하의, 겉옷의 수량을 모두 곱해버리면 된다.
하지만, 제한사항에 최소 1가지는 입어야 된다고 했으니
아래 1가지의 경우의수는 제외 해야 한다.
얼굴 : 아무것도 하지 않음
상의 : 아무것도 하지 않음
하의 : 아무것도 하지 않음
겉옷 : 아무것도 하지 않음

그러므로, 얼굴, 상의, 하의, 겉옷의 수량(아무것도 하지 않는 경우의수를 포함한)을 모두 곱한다음
곱한수에 -1을 하면 된다.
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;

    for (int i = 0; i < clothes.size(); i++) um[clothes[i][1]]++;
    for (pair<string, int> elem : um) answer *= elem.second + 1;

    return answer - 1;
}

int main() {
    vector<vector<string>> clothes;
    vector<string> temp;
    temp.push_back("yellow_hat");
    temp.push_back("headgear");
    clothes.push_back(temp);
    temp.clear();
    temp.push_back("blue_sunglasses");
    temp.push_back("eyewear");
    clothes.push_back(temp);
    temp.clear();

    temp.push_back("green_turban");
    temp.push_back("headgear");
    clothes.push_back(temp);
    temp.clear();

    solution(clothes);
    return 0;
}