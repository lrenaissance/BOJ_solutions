//problem: https://www.acmicpc.net/problem/1063
//date: 20230924

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    char alphabet;
    int row;
}position;

void move(position king, position stone, string* route, int route_size) {
    for (int i = 0; i < route_size; i++) {
        position tmp1, tmp2;
        tmp1.alphabet = king.alphabet;
        tmp1.row = king.row;
        tmp2.alphabet = stone.alphabet;
        tmp2.row = stone.row;
        if (route[i] == "R") {
            king.alphabet++;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.alphabet++;
            }
        }
        else if (route[i] == "L") {
            king.alphabet--;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.alphabet--;
            }
        }
        else if (route[i] == "B") {
            king.row--;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.row--;
            }
        }
        else if (route[i] == "T") {
            king.row++;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.row++;
            }
        }
        else if (route[i] == "RT") {
            king.row++;
            king.alphabet++;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.row++;
                stone.alphabet++;
            }
        }
        else if (route[i] == "LT") {
            king.row++;
            king.alphabet--;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.row++;
                stone.alphabet--;
            }
        }
        else if (route[i] == "RB") {
            king.row--;
            king.alphabet++;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.row--;
                stone.alphabet++;
            }
        }
        else if (route[i] == "LB") {
            king.row--;
            king.alphabet--;
            if (king.alphabet == stone.alphabet && king.row == stone.row) {
                stone.row--;
                stone.alphabet--;
            }
        }
        if (king.row < 1 || king.row>8 || king.alphabet < 'A' || king.alphabet>'H'||stone.row < 1 || stone.row>8 || stone.alphabet < 'A' || stone.alphabet>'H') {
            king.row = tmp1.row;
            king.alphabet = tmp1.alphabet;
            stone.row = tmp2.row;
            stone.alphabet = tmp2.alphabet;
        }
    }

    printf("%c%d\n", king.alphabet, king.row);
    printf("%c%d\n", stone.alphabet, stone.row);
}

int main() {
    position p1, p2;
    string st1, st2;
    int n;
    cin >> st1 >> st2 >> n;
    
    //초기 위치
    p1.alphabet = st1.at(0);
    p1.row = st1.at(1)-48; //char로 들어오기 때문에 빼서 입력받은 숫자로 바꿔줘야함

    p2.alphabet= st2.at(0);
    p2.row= st2.at(1)-48;

    string* route = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> route[i];
    }

    move(p1, p2, route, n);
 
    return 0;
}

/*문제 이해: 구현이 어렵지는 않으나 문제를 이해하지 못해서 여러번 시도하였음. 핵심은
1. 돌은 가만히 있지만 킹이 자기 자리로 이동하게 될 경우에만 이동을 한다.
2. 킹이나 돌 중 하나라도 체스판 밖으로 나가게 되면 이동은 무효
*/