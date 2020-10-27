/*
https://programmers.co.kr/learn/courses/30/lessons/17683
문제 설명
라디오를 자주 듣는 네오는 라디오에서 방금 나왔던 음악이 무슨 음악인지 궁금해질 때가 많다.
그럴 때 네오는 다음 포털의 '방금그곡' 서비스를 이용하곤 한다. 방금그곡에서는 TV, 라디오 등에서 나온 음악에 관해 제목 등의 정보를 제공하는 서비스이다.

네오는 자신이 기억한 멜로디를 가지고 방금그곡을 이용해 음악을 찾는다.
그런데 라디오 방송에서는 한 음악을 반복해서 재생할 때도 있어서 네오가 기억하고 있는 멜로디는 음악 끝부분과 처음 부분이 이어서 재생된 멜로디일 수도 있다.
반대로, 한 음악을 중간에 끊을 경우 원본 음악에는 네오가 기억한 멜로디가 들어있다 해도 그 곡이 네오가 들은 곡이 아닐 수도 있다.
그렇기 때문에 네오는 기억한 멜로디를 재생 시간과 제공된 악보를 직접 보면서 비교하려고 한다. 다음과 같은 가정을 할 때 네오가 찾으려는 음악의 제목을 구하여라.

방금그곡 서비스에서는 음악 제목, 재생이 시작되고 끝난 시각, 악보를 제공한다.
네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
각 음은 1분에 1개씩 재생된다. 음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다. 음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
음악이 00:00를 넘겨서까지 재생되는 일은 없다.
조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
조건이 일치하는 음악이 없을 때에는 `(None)`을 반환한다.

[입력 형식]
입력으로 네오가 기억한 멜로디를 담은 문자열 m과 방송된 곡의 정보를 담고 있는 배열 musicinfos가 주어진다.

 - m은 음 1개 이상 1439개 이하로 구성되어 있다.
 - musicinfos는 100개 이하의 곡 정보를 담고 있는 배열로, 각각의 곡 정보는 음악이 시작한 시각, 끝난 시각, 음악 제목, 악보 정보가 ','로 구분된 문자열이다.
 - 음악의 시작 시각과 끝난 시각은 24시간 HH:MM 형식이다.
 - 음악 제목은 ',' 이외의 출력 가능한 문자로 표현된 길이 1 이상 64 이하의 문자열이다.
 - 악보 정보는 음 1개 이상 1439개 이하로 구성되어 있다.

[출력 형식]
조건과 일치하는 음악 제목을 출력한다.

[입출력 예시]
m                  musicinfos                                               answer
ABCDEFG            [12:00,12:14,HELLO,CDEFGAB, 13:00,13:05,WORLD,ABCDEF]    HELLO
CC#BCC#BCC#BCC#B   [03:00,03:30,FOO,CC#B, 04:00,04:08,BAR,CC#BCC#BCC#B]     FOO
ABC                [12:00,12:14,HELLO,C#DEFGAB, 13:00,13:05,WORLD,ABCDEF]   WORLD

[설명]
첫 번째 예시에서 HELLO는 길이가 7분이지만 12:00부터 12:14까지 재생되었으므로 실제로 CDEFGABCDEFGAB로 재생되었고, 이 중에 기억한 멜로디인 ABCDEFG가 들어있다.
세 번째 예시에서 HELLO는 C#DEFGABC#DEFGAB로, WORLD는 ABCDE로 재생되었다. HELLO 안에 있는 ABC#은 기억한 멜로디인 ABC와 일치하지 않고, WORLD 안에 있는 ABC가 기억한 멜로디와 일치한다.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, int> tm;
unordered_map<string, string> um = {
    {"C","A"},
    {"C#","B"},
    {"D","C"},
    {"D#","D"},
    {"E","E"},
    {"F","F"},
    {"F#","G"},
    {"G","H"},
    {"G#","I"},
    {"A","J"},
    {"A#","K"},
    {"B","L"}
};

struct node {
    string name;
    int time, index;
};

vector<string> fn_split(string str) {
    vector<string> vect;
    int a = 0;
    str.insert(str.length(), ",");

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            string temp = str.substr(a, i - a);
            a = i + 1;
            vect.push_back(temp);
        }
    }

    return vect;
}

string fn_change(string str) {
    string temp = "";
    string ret = "";
    str.insert(str.length(), " ");
    
    for (int i = 0; i < str.length() - 1; i++) {
        temp = "";
        temp += str[i];
        temp += str[i + 1];
        if (um.count(temp) > 0) ret += um[temp];
        else {
            string s_tmp = "";
            s_tmp += str[i];
            if (str[i] == '#') continue;
            else ret += um[s_tmp];
        }
    }

    return ret;
}

int fn_time(string st, string end) {
    int time = (stoi(end.substr(0, 2)) - stoi(st.substr(0, 2))) * 60 + (stoi(end.substr(3, 2)) - stoi(st.substr(3, 2)));
    return time;
}

string fn_music(string music, int time) {
    string temp = "";
    for (int i = 0; i < time; i++) {
        temp += music[i % music.length()];
    }
    return temp;
}

void fn_music_split(string music, int size) {
    if (music.length() < size) size = music.length();
    for (int i = 0; i <= music.length() - size; i++) {
        tm[music.substr(i, size)]++;
    }
}

bool cmp(node a, node b) {
    if (a.time > b.time) return true;
    if (a.time < b.time) return false;
    return a.index < b.index;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<string> vect;
    vector<node> ret;
    string music;
    m = fn_change(m);
    int time;

    for (int i = 0; i < musicinfos.size(); i++) {
        vect = fn_split(musicinfos[i]);
        time = fn_time(vect[0], vect[1]);
        music = fn_music(fn_change(vect[3]), time);
        fn_music_split(music, m.size());
        if (tm.count(m) > 0) ret.push_back({vect[2], time, i});
        tm.clear();
    }

    sort(ret.begin(), ret.end(), cmp);

    if (ret.size() == 0) answer = "(None)";
    else answer = ret[0].name;

    return answer;
}

int main() {
    //A#, ["13:00,13:02,HAPPY,B#A#"], HAPPY
    //CDEFGAC, ["12:00,12:06,HELLO,CDEFGA"], (None)
    //CCB, ["03:00,03:10,FOO,CCB#CCB","04:00,04:08,BAR,ABC"], FOO

    //vector<string> musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
    //vector<string> musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:14,WORLD,ABCDEF" };
    vector<string> musicinfos = { "13:00,13:02,HAPPY,B#A#" };

    solution("A#", musicinfos);

    return 0;
}