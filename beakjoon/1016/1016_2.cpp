#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
 
int main(){
    long long min, max;
    // scanf("%lld %lld", &min, &max);
    min = 97, max = 10000;
    /*
    isP[i]: i가 소수면 true
    최대 크기가 이렇게 괴상한 이유는 max의 최대값의 제곱근이어서
    */
    bool isP[1001002];
    memset(isP, 1, sizeof(isP));
    // 에라토스테네스의 체로 소수들을 뽑아 vector로 보관
    vector<int> prime;
    prime.push_back(2);
    int limit = sqrt(max)+1;
    for(int i=3; i<limit; i+=2){
        if(!isP[i]) continue;
        prime.push_back(i);
        // 주의: i가 크면 i*i이 int 범위를 넘어갈 수 있음
        for(long long j=1LL*i*i; j<limit; j+=i*2)
            isP[j] = false;
    }
 
    // 이제부터 isP[i]: i-min이 제곱ㄴㄴ수면 true
    memset(isP, 1, sizeof(isP));
    for(int j = 0; j < prime.size(); j++){
        int p = prime[j];
        // 모든 소수에 대해서 주어진 구간 안에서만 체로 거르기
        long long n = 1LL*p*p;
        // i의 시작 인덱스는 min 이상의 최소인 p*p의 배수
        for(long long i=(min%n?(min/n+1)*n:min); i<=max; i+=n)
            isP[i-min] = false;
    }
 
    // 체로 걸러지지 않은 칸의 개수가 답
    int result = 0;
    for(int i=0; i<max-min+1; i++)
        result += isP[i];
    printf("%d\n", result);
}
