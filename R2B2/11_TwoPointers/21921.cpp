//problem: https://www.acmicpc.net/problem/21921
//date: 20240306

#include <iostream>

using namespace std;

int main(void) {
    int n, x,s,e;
    int tmp = 0;
    cin >> n >> x;
    s = 0; e = x-1; //투포인터

    int* v = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //맨 첫번째 칸
    for (int i = 0; i < x; i++) {
        tmp += v[i];
    }
    int max = tmp;
    int cnt = 1;

    for (int s = 0; s < n - x; s++) {
        tmp = tmp - v[s] + v[e+1];

        if (max < tmp) {
            max=tmp;
            cnt = 1;
        }
        else if(max==tmp){
            cnt++;
        }
        e++;
    }

    if (max == 0) {
        cout << "SAD";
    }
    else {
        cout << max<<"\n";
        cout << cnt;
    }

    return 0;
}