//problem: https://www.acmicpc.net/problem/1152
//date: 20230924

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int cnt = 0;
    getline(cin, s);//getline으로 통으로 입력받기
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' ') // 공백 확인
            cnt++;
    }
    if(s.length()==cnt){
        printf("0");//공백만 입력될 때
        return 0;
    }
    cnt=0;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' '&&(i!=0 &&i!=s.length()-1))//띄어쓰기 개수 세기(문장 시작과 끝은 단어 개수에 영향 없으므로 제외)
            cnt++;
    }
    
    printf("%d", cnt+1);//단어 개수=띄어쓰기 개수+1
    return 0;
}

//공백이 문장에 앞뒤에 있으면 단어 개수에 반영되지 않음+공백만 있을 경우에는 단어가 없음