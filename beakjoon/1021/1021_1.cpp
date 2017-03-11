#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
    freopen("input.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    
    vector<int> v;    
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    deque<int> q;
    for(int i=1; i<=n; i++)
        q.push_back(i);
    
    int result = 0;
    
    for(int i=0; i<m; i++){
        int now = v[i];
        int num = 0;
        int s = q.size();
        //왼쪽으로 shift해봄
        for(int j=0; j<q.size(); j++){
            int f = q.front();
            q.pop_front();
            if(f == now)//빼려는 것
                break;
            num++;
            q.push_back(f);
        }
        
        result += min(num, s-num);
    }
    
    cout << result;
    
}
