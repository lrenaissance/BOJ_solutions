//problem: https://www.acmicpc.net/problem/2607
//date: 20231009

#include <iostream>
#include <vector>

using namespace std;

int check_word(vector<int>& v1, vector<int>& v2) {//습관적으로 int return 함수로 작성했으나 bool로도 가능
	int status = 0;//이상은 한 번만 발생가능
	int diff = 0;//개수 차이 저장용
	for (int i = 0; i < 26; i++) {
		if (v1[i] == v2[i]) { //개수 같음
			continue;
		}
		else if (v1[i]-v2[i]<-1 || v1[i] - v2[i] >1) { //1보다 크게 차이 나면 커버 불가능
			return 0;
		}
		else if (v1[i] - v2[i] == -1 || v1[i] - v2[i] == 1) {//1 차이 날 경우 추가 제거 교체로 가능
			diff += v1[i] - v2[i];
			//이미 앞에서 차이 났었는데 또 차이나면 불가능(예외: diff=0이 될 때 교체로 해결)
			if (status == 1 && diff!=0) {
				return 0;
			}
			status = 1;
		}
	}
	return 1;
}

int main(void) {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int cnt = 0;
	string word, str;
	cin >> n;
	vector<int> v1(26);//알파벳 26개
	cin >> word;
	for (int j = 0; j < word.length(); j++) {
		char c = word.at(j);
		v1[c - 65]++; //ASCII 이용 입력
	}
	for (int i = 1; i < n; i++) {
		cin >> str;
		vector<int> v2(26);
		for (int j = 0; j < str.length(); j++) {
			char c = str.at(j);
			v2[c - 65]++;
		}
		if (check_word(v1,v2) == 1) {//return==1: 비슷한 단어
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}