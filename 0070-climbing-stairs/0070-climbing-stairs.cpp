class Solution {
public:
    int fun(vector<int>& dp, int n){
        if(n == 1 || n == 2){
            return n;
        }
        int first;
        if(dp[n-1] == -1){
            first = fun(dp, n-1);
            dp[n-1] = first;
        }else{
            first = dp[n-1];
        }
        int second;
        if(dp[n-2] == -1){
            second = fun(dp, n-2);
            dp[n-2] = second;
        }else{
            second = dp[n-2];
        }
        return first + second;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return fun(dp, n);
    }
};