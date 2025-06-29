class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int found = 0;
        int index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            index = mid;
        }
        if(index < n-1){
            return low;
        }else {
            return high +1;
        }
        
    }
};