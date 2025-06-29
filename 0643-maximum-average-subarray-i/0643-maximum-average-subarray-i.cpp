class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = INT_MIN;
        int j = 0;
        double avg = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + nums[i];
            if(i - j + 1 == k){
                avg = sum/k;
                ans = max(ans, avg);
                sum = sum - nums[j];
                j++;
            }
        }
        return ans;
    }
};