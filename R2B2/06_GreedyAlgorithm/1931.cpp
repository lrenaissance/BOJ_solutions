//problem: https://www.acmicpc.net/problem/1931
//date: 20231012

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct meeting {
    int start;
    int end;
};

bool cmp(meeting a, meeting b) {
    if (a.end == b.end) {//끝나는 시간 같으면 start 먼저
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt = 1;
    int max = 0;
    vector<meeting> mt;
    cin >> n;
    for (int i = 0; i < n; i++) {
        meeting m;
        cin >> m.start >> m.end;
        mt.push_back(m);
    }

    int* list = new int[max + 1]();
    sort(mt.begin(), mt.end(), cmp);
    max = mt[0].end;
    for (int i = 1; i < n; i++) {
        if (mt[i].start >= max) {//시작 시간이 max 이상이면 추가 가능
            cnt++;
            max = mt[i].end;
        }
    }
    cout << cnt;
    return 0;
}