class Solution {
public:
    int rec(string s1, string s2, int i, int j, vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = rec(s1,s2,i-1,j-1, dp);
        }else{
            return dp[i][j] = 1 + min(rec(s1,s2,i-1,j-1, dp), min(rec(s1,s2,i,j-1, dp),rec(s1,s2,i-1,j, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = word1.size()-1;
        int j = word2.size()-1;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return rec(word1,word2,i,j, dp);
    }
};