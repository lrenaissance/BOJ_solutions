//problem: https://www.acmicpc.net/problem/16563
//date: 20230724

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void prime_check(int n, vector<int> &v){ //instead of checking whether it is a prime or not, record its least prime factor
    for(int i=2;i<=sqrt(n);i++){
        if(v[i]==0){
            for(int j=i*i;j<=n;j+=i){
                if(v[j]!=0){
                    continue;
                }
                else{
                    v[j]=i;
                }
            }
        }
    }
}

int get_prime(int n, vector<int> &v){ //divide the number with its recorded prime factor and search the prime factor of the new number again
    int j=n;
    for(;v[j]!=0;j/=v[j]){
            cout<<v[j]<<" ";
    }
    return j;
}

int main() {
    int n, max=0;
    int last;
    cin>>n;
    int *k=new int[n];
    
    for(int i=0;i<n;i++){//k inputs
        cin>>k[i];
        if(max<k[i]){//the space larger than max is unnecessary
            max=k[i];
        }
    }
    vector<int> v(max);
    prime_check(max,v); //check the prime factors
    
    for(int i=0;i<n;i++){
        last=get_prime(k[i],v); //get the prime factors of the number(in an ascending order)
        cout<<last<<"\n";
    }
    
    return 0;
}