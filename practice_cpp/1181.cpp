//problem: https://www.acmicpc.net/problem/1181
//date: 20230927

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

int main() {
    int n;
    string tmp;
    cin >> n;
    string* str = new string[n];

    for (int i = 0; i < n; i++) {
        str[i] = "A"; //대문자 안 들어오니까 이걸로 초기화(no capital letters)
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        str[i] = tmp;
        for (int k = 0; k < i; k++) {
            if (str[k] == tmp) {
                str[i] = "A";
                break;
            }
        }
    }

    sort(str, str + n, cmp);

    for (int i = 0; i < n; i++) {
        if (str[i] != "A") {
            cout << str[i]<<"\n";
        }
    }
    return 0;
}