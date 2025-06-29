class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int z){
        int cnt = 0;
        int nOfB = 0;
        for(int x: bloomDay){
            if(z >= x){
                cnt++;
            }
            else {
                nOfB += cnt/k;
                cnt = 0;
            }    
        }
        nOfB += cnt/k;
        

        return nOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int s = INT_MAX;
        int e = INT_MIN;
        for(int i = 0;i<n; i++){
            if(bloomDay[i] > e){
                e = bloomDay[i];
            }
            if(bloomDay[i] < s){
                s = bloomDay[i];
            }
        }
        if((long long)m*k > n){
            return -1;
        }
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                e = mid -1;
            }else{
                s = mid + 1;
            }
        }
        return ans;

    }
};