//problem: https://www.acmicpc.net/problem/7785
//date: 20230717

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int num;
    string name, status;
    set<string, greater<string>> cp;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> name >> status;
        if (status == "enter") {
            cp.insert(name);
        }
        else {//leave
            cp.erase(name);
        }
    }

    for (auto iter = cp.begin(); iter != cp.end(); iter++) {//used iter
        cout << *iter<< '\n';
    }

    return 0;
}
