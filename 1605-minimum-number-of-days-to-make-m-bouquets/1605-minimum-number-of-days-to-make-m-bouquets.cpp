class Solution {
public:
    int find(vector<int>& arr, int m, int k, int mid){
        int cnt = 0;
        int no = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] <= mid){
                cnt++;
                if(cnt == k){
                    no++;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return no;
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long int low = *min_element(arr.begin(), arr.end());
        long long int high = *max_element(arr.begin(), arr.end());
        long long ans = -1;
        
        while(low <= high){
            long long int mid = low + (high - low)/2;
            int no = find(arr, m, k, mid);
            if(no >= m){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};