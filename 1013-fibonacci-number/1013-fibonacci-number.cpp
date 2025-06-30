class Solution {
public:
    int fib(int n) {
        if(n == 1 || n == 0){
            return n;
        }
        int z1 = fib(n-1);
        int z2 = fib(n-2);
        return z1+z2;
    }
};