class Solution {
public:
    int fun(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return n;
        }
        int first;
        if(dp[n-1] == -1){
            first = fun(n-1, dp);
            dp[n-1] = first;
        }else{
            first = dp[n-1];
        }
        int second;
        if(dp[n-2] == -1){
            second = fun(n-2, dp);
            dp[n-2] = second;
        }else{
            second = dp[n-2];
        }
        return first + second;
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fun(n, dp);
    }
};