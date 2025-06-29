class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int ans = INT_MAX;
        int index = 0;
        int sum = 0;
        int sum2 =0;
        for(int i = 0; i<n; i++){
            sum2 = sum2 + nums[i];
        }

        if(sum2 < target){
            return 0;
        }
        for(int i =0; i<n; i++){
            // sum = 0;
            sum = sum + nums[i];
            while(sum >= target){
                index = i - j + 1;
                ans = min(ans, index);
                index--;
                sum = sum - nums[j];
                j++;
            }
        }
        return ans;
    }
};