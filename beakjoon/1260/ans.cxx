#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>


vector<vector<int>> adj;
vector<bool> visited;
int n, m , s;
vector<int> ans;
void dfs(int here) {

    visited[here] = true;
    ans.push_back(there);
    for(auto &there : adj[here]) {
        if(!visited[there]) {
            dfs(there);
        }
    }
}


void bfs() {


    visited[s] = true;
    queue<int> q; 
    q.push(s);
    while(!q.empty()){
        int here = q.front();
        q.pop();

        ans.push_back(here);

        for(auto& there : adj[here]) {
            if(!visited[there]){
                q.push(there);
                visited[there] = true;
            }
        }
    }

}
int main() {
    scanf("%d %d %d", &n, &m, &s);

    adj = vector<vector<int>>(n + 1, vector<int>);
    

    for(int i = 0; i < m; i++){
        int here, there;
        scanf("%d %d", &here, &there);

        adj[here].push_back(there);
        adj[there].push_back(here);
    }

    for(auto& ad : adj){
        sort(ad.begin(), ad.end());
    }

    visited = vector<bool>(n + 1, false);

    dfs(s);

    for(const auto& a : ans) {
        printf("%d ", a);
    }

    ans = vector<int>();
    visited = vector<bool>(n + 1, false);


}