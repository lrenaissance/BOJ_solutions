//problem: https://www.acmicpc.net/problem/9375
//date: 20230720

#include <iostream>
#include <map>

using namespace std;

int main(void) {

	int n,t, cases;
	string name,type;
	map<string, int> m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cases = 1; 
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> name >> type;
			if (m.find(type) == m.end()) {//element with a new type
				m.insert({type,1});
			}
			else { //already exists
				m[type]++;
			}
		}
		for (auto iter=m.begin(); iter!= m.end(); iter++) { //cannot randomly access the map -> use iterator
			cases = cases * (1 + iter->second); 
			//access the map's key: iter->first
			//access the map's value: iter->second
		}
		cout << --cases<<"\n"; //erase the case with no selection(naked situation)
		m.clear(); //clears all the elements inside the map
	}

	return 0;
}