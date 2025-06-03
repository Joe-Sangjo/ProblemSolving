class Solution {
public:
    vector<bool> visited;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited = vector<bool>(false, n);


        visited[source] = true;
        for(const auto& adge : edges) {
            const auto& here = adge[0];
            const auto& there = adge[1];
            if(here == source && !visited[there]){
                dfs(edges, there);
            }

            if(there == source && !visited[here]) {
                dfs(edges, here);
            }
        }

        return visited[destination];
    }

    void dfs(const vector<vector<int>>& edges, const int node) {
        
        visited[node] = true;
        for(const auto& adge : edges) {
            const auto& here = adge[0];
            const auto& there = adge[1];
            if(here == node && !visited[there]) {
                dfs(edges, there);
            }

            if(there == node && !visited[here]) {
                dfs(edges, here);
            }
        }
    }
};