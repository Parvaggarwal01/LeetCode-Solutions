class Solution {
public:
    int binary(vector<int>& arr, int low, int high, int target){
        if(low > high){
            return -1;
        }
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            return binary(arr, mid+1, high, target);
        }else{
            return binary(arr, low, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = binary(nums, 0, n-1, target);
        return ans;
    }
};