class Solution {
public:
    bool isValid(vector<int>& arr, int maxSum, int k){
        int count = 1, currSum = 0;
        for(int x: arr){
            if(currSum + x > maxSum){
                count++;
                currSum = x;
                if(count > k){
                    return false;
                }
            }else{
                currSum += x;
            }
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isValid(arr, mid, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};