class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long count(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = count(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions  = n / 2;  

        long long result =
            (count(5, evenPositions) * count(4, oddPositions)) % MOD;

        return (int)result;
    }
};
