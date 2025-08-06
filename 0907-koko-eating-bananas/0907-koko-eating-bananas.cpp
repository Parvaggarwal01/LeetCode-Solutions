class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());
        long long ans = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long hrs = 0;
            for (int pile : piles) {
                hrs += ceil((double)pile / mid);
            }
            if (hrs <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};