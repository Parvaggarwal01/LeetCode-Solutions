class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i<n; i++){
            long long small = nums[i];
            long long large = nums[i];
            for(int j = i; j<n; j++){
                small = min(small, (long long)nums[j]);
                large = max(large, (long long)nums[j]);
                sum += (large - small);
            }
        }
        return sum;
    }
};