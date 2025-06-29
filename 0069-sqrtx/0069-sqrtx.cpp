class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;
        long long int mid = low + (high - low)/2;
        while(low <= high){
            
            long long int sq = mid*mid;
            if(sq == x){
                return mid;
            }
            else if(sq > x){
                high = mid-1;
            } else {
                ans = mid;
                low = mid+1;
            }
            mid = low + (high - low)/2;
        }

        return ans;
    }
};