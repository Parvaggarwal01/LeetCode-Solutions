class Solution {
public:
    long long int find(vector<int>& arr, int mid){
        long long int ans = 0;
        for(int i = 0; i<arr.size(); i++){
            long long int num = (arr[i] + mid - 1) / mid;
            ans = ans + num;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& arr, int t) {
        long long int low = 1;
        long long int high = *max_element(arr.begin(), arr.end());
        long long final = 0;
        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int  ans = find(arr, mid);
            if(ans <= t){
                final = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return final;
    }
};