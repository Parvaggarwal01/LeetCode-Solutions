class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;
        for(int nm : adj[node]){
            if(!vis[nm]){
                dfs(nm, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> Vis(n, false);
        vector<vector<int>> adj(n);
        
        for(auto& edge : edges){
          int u = edge[0];
          int v = edge[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        dfs(source, adj, Vis);

        return Vis[destination];
        
    }
};