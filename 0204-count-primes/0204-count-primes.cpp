class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;

        vector<bool> prime(n, false);

        for (int x = 1; x * x < n; x++) {
            for (int y = 1; y * y < n; y++) {
                int num = 4 * x * x + y * y;
                if (num < n && (num % 12 == 1 || num % 12 == 5))
                    prime[num] = !prime[num];

                num = 3 * x * x + y * y;
                if (num < n && num % 12 == 7)
                    prime[num] = !prime[num];

                num = 3 * x * x - y * y;
                if (x > y && num < n && num % 12 == 11)
                    prime[num] = !prime[num];
            }
        }

        for (int i = 5; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i * i)
                    prime[j] = false;
            }
        }

        // 2 and 3 are prime
        int count = (n > 2) + (n > 3);
        for (int i = 5; i < n; i++) {
            if (prime[i]) count++;
        }

        return count;
    }
};
