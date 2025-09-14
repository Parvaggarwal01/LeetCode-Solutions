class Solution {
public:
    long long int totalHr(vector<int>& arr, long long int h){
        long long int total = 0;
        for(int i = 0; i<arr.size(); i++){
            total += ceil((double)arr[i]/(double)h);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int low = 1;
        long long int high = *max_element(arr.begin(), arr.end());
        int ans = 0;
        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int total = totalHr(arr, mid);
            if(total <= h){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};