#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
typedef long long ll;
using namespace std;
ll N, M;
ll Z;
const ll INF = 2000000000;
ll optimal();
ll decision(int win);
int main(){
    freopen("input.txt","r",stdin);
    setbuf(stdout, NULL);
 
    int TC; cin>>TC;
 
    for(int test_case = 0 ; test_case < TC; test_case ++){
        cin>>N>>M;
        Z = 100*M/N;
        // cout<<Z<<endl;
        ll cand = optimal();
        if(cand > INF){
            cout<<-1<<endl;
        }
        else{
            cout<<cand<<endl;
        }
    }
    return 0;
}
 
ll optimal(){
    ll lo = 0, hi = INF+10;    //최소 0, 최대 INF + 1
    ll mid;
    while(lo + 1 < hi){
        mid = (lo + hi)/2;
        if(Z == decision(mid)){
            lo = mid; //아직 승리 횟수가 충분치 않다는 의미이므로 범위를 올려준다.
        }
        else{
            hi = mid; //승리가 더 갔으니까 범위를 내려준다.
        }
    }
    return hi;
}
ll decision(int w){
    return 100*(M+w)/(N+w); //승률을 리턴
}
