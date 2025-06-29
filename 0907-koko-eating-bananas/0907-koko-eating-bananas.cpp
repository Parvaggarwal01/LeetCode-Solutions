class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = 1;
        for(int i = 0; i<n; i++){
            if(right < piles[i]){
                right = piles[i];
            }
        }
        while(left < right){
            int mid = left + (right - left)/2;
            long long int hour = 0;

            for(int i = 0; i<n; i++){
                hour = hour + (piles[i] + mid - 1)/mid;
            }

            if(hour <= h){
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};