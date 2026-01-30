class Solution {
public:
    double power(double x, long long n){
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }
        if(n%2 == 0){
            return myPow(x*x, n/2);
        }
        return x * myPow(x, n-1);
    }
    double myPow(double x, int n) {
        long long N = n; 

        if(N < 0){
            return (1.0 / power(x, -1 * N));
        }
        return power(x, N);
    }
};