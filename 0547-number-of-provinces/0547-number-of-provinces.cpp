class Solution {
public:

    void dfs(int start, vector<vector<int>> &adjlist, vector<bool>& vls){
        vls[start] = true;
        for(int x : adjlist[start]){
            if(!vls[x]){
                dfs(x, adjlist, vls);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjlist(isConnected.size());
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = 0; j<isConnected[i].size(); j++){
                if(isConnected[i][j] ==  1 && i != j){
                    adjlist[i].push_back(j);
                }
            }
        }
        vector<bool> vis(isConnected.size(), false);
        int count = 0;
        for(int i = 0; i<isConnected.size(); i++){
            if(!vis[i]){
                count++;
                dfs(i, adjlist, vis);
            }
        }
        return count;
    }
};