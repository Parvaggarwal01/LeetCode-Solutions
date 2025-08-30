class Solution {
public:
    int firstO(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == x){
                first = mid;
                high = mid - 1;
            }else if(nums[mid] < x){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return first;
    }
    int lastO(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int last = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == x){
                last = mid;
                low = mid + 1;
            }else if(nums[mid] < x){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstO(nums, target);
        int last = lastO(nums, target);
        return {first, last};
    }
};