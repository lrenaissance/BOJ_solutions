//problem: https://www.acmicpc.net/problem/14425
//date: 20230720

#include <iostream>
#include <set>

using namespace std;

int main(void) {

	int n, m,val=0;
	string str;
	set<string> s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) { 
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (s.find(str)!=s.end()) {//checks if there is str in s
			//find() returns the iterator - if there is no element, it returns end()
			val++;
		}

	}
	//val = n + m - s.size();
  //I thought I could just calculate like this, but this can only be right when there are no duplication among m strings
  //always check duplication conditions

	cout << val;

	return 0;
}