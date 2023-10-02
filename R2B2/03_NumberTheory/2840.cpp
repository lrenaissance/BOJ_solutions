//problem: https://www.acmicpc.net/problem/2840
//date: 20230930

#include <iostream>

using namespace std;

int main(void) {
	int n, k, move,p;
	int current = 0;
	int index=1; //index 1: possible, 0: impossible
	char alphabet;

	cin >> n >> k;
	char* wheel = new char[n];
	for(int i=0;i<n;i++){
        wheel[i]='?'; //초기화
    }

	for (int i = 0; i < k; i++) {
		cin >> move >> alphabet;
		p = (current + move) % n;
		current = p;

        if(index==0){
            continue;
        }

		//중복검사
		for (int q = 0; q < n; q++) {
			if ((wheel[q] == alphabet) && (q != p)) {
				index = 0;
				break;
			}
		}
		if(index==1){
		    if (wheel[p] =='?') { //empty
			    wheel[p] = alphabet;
		    }
		    else if (wheel[p] != alphabet) { //내 자리에 나와 다른 알파벳이 이미 있음
			    index = 0;
			    continue;
		    }   
	    }
	}
	
	if(index==0){
	    printf("!");
	    return 0;
	}
	
	//출력
	if (p == n - 1) {
		for (int i = n - 1; i >= 0; i--) {
			printf("%c", wheel[i]);
		}
	}
	else {
		for (int i = p; i >= 0; i--) {
			if (wheel[i] == '?')
				printf("?");
			else
				printf("%c", wheel[i]);
		}
		for (int i = n - 1; i >p; i--) {
			if (wheel[i] =='?')
				printf("?");
			else
				printf("%c", wheel[i]);
		}
	}	

	return 0;
}

/*아이디어: 문제가 원형큐와 비슷하다고 느껴서, 나머지를 이용하여 구현*/

/*시행착오: 아무리 생각해도 내 코드가 맞는데 뭐 때문에 틀렸는지 알 수 없었던 문제. 
프로그램을 입력받는 중에 해당 바퀴가 존재할 수 없다는 것을 알면 바로 종료해버리는 식으로 구현해서 틀린 것이었음
(아직도 뒤에 입력받아야 하는데 프로그램이 종료되어버리니까). index 변수를 추가해서 문제가 생기면 
index만 수정한 후 출력을 다르게 하는 식으로 수정하였음.*/