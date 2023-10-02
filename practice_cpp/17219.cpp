//problem: https://www.acmicpc.net/problem/17219
//date: 20230928

#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    map<string, string> m1;
    int n,m;
    string site, pw;
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        cin >> site>>pw;
        m1[site] = pw;
    }
    for (int i = 0; i < m; i++) {
        cin >> site;
        pw = m1[site];
        cout<< pw<<"\n";
    }

    return 0;
}

//simple map problem