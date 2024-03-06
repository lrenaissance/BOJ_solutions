//problem: https://www.acmicpc.net/problem/2470
//date: 20240306

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int l, r; //투포인터
    l = 0; r = n - 1;
    
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    sort(val, val + n);//정렬

    int sum,min;
    sum = val[l] + val[r];
    min = sum;
    int s = l;
    int e=r; //s=min_l, e=min_r

    while (l<r) {
        if (abs(min) > abs(sum)) {
            min = sum;
            s = l; e = r;
        }
        if (sum > 0) {
            r--;
        }
        else if(sum<0) {
            l++;
        }
        else {//sum==0
            break;
        }
        sum = val[l] + val[r];
    }

    cout << val[s] << " " << val[e];

    return 0;
}