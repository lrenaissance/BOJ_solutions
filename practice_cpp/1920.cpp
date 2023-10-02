//problem: https://www.acmicpc.net/problem/1920
//date: 20230927

#include <iostream>
#include <algorithm>

using namespace std;

bool search_binary(int *v, int val, int low, int high) { //O(logn)
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;

        if (val == v[mid]) {
            return true;
        }
        else if (val > v[mid]) {
            low = mid + 1;//오른쪽 subarray
        }
        else {
            high = mid - 1;//왼쪽 subarray
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false); //빠른 입출력(fast IO)

    int n, m, val;
    cin >> n;
    int* v1 = new int[n]();
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    sort(v1,v1+n);//O(NlogN)

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        if (search_binary(v1,val,0,n-1)==false) { //없다
            cout <<"0"<< "\n";
        }
        else { //있다
            cout << "1"<< "\n";
        }
    }
    return 0;
}

/*시행착오: 시간초과 이슈.
N(1 ≤ N ≤ 100,000), M(1 ≤ M ≤ 100,000)이라 반복문 안에서 순차탐색 돌리면
O(N^2)으로 시간 초과(시간제한 1초) -> binary search - O(logN)으로 해결
binary search: 정렬된 array에서 mid 값을 update하면서 왼쪽, 오른쪽 subarray 탐색
*/