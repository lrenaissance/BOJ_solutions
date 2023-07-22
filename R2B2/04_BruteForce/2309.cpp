//problem: https://www.acmicpc.net/problem/2309
//date: 20230721

#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int height, sum = 0; 
	set<int> s;
	for (int i = 0; i < 9; i++) {
		cin >> height;
		s.insert(height);
		sum += height;
	}
	sum -= 100;
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		if(sum<*iter ||sum==2*(*iter)){//*iter bigger than sum is unqualified and there couldn't be same *iter in the given input
		    continue;
		}
		if (s.find(sum - *iter) != s.end()) {
			s.erase(*iter);
			s.erase(sum - *iter);
			break; //(important!!)since there could be multiple answers
		}
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter<<endl;
	}

	return 0;
}