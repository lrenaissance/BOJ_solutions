//problem: https://www.acmicpc.net/problem/2751, https://www.acmicpc.net/problem/2750 (same question with smaller input)
//date: 20230718

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int num,val;
    set<int> s;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> val;
        s.insert(val);
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << "\n";
    }

    return 0;
}
