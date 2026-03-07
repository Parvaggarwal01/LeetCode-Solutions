class Solution {
public:
    int minFlips(string s) {
        const int n = s.length();
        int p = 0, k = 0;
        for(const char c : s){
            k += p ^ c & 1;
            p ^= 1;
        }
        int r = min(k, n - k);
        if(n & 1){
            p = 0;
            for(const char c : s){
                k += (p ^ c & 1 ^ 1) - (p ^ c & 1);
                p ^= 1;
                r = min(r, min(k, n - k));
            }
        }
        return r;
    }
};