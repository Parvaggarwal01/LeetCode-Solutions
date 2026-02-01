class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int fMin = INT_MAX;
        int sMin = INT_MIN;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i] < fMin){
                sMin = fMin;
                fMin = nums[i];
            }else if(nums[i] < sMin){
                sMin = nums[i];
            }
        }
        return nums[0] + fMin + sMin;
    }
};