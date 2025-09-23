class Solution {
public:
    int func(vector<int>& arr, int mid){
        int day=1;
        int load=0;
        for(int i = 0; i<arr.size(); i++){
            if(load + arr[i] > mid){
                day = day+1;
                load = arr[i];
            }else{
                load += arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int day = func(arr, mid); 
            if(day <= days){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};