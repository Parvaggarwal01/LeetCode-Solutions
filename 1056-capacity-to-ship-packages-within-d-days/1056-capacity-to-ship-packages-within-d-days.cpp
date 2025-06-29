class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxw = -1;
        int totalw = 0;
        int n = weights.size();
        for(int i = 0; i<n; i++){
            if(maxw < weights[i]){
                maxw = weights[i];
            }
            totalw = totalw + weights[i];
        }

        while(maxw < totalw){
            int mid = maxw + (totalw - maxw)/2;
            int curr = 0;
            int day = 1;
            for(int i = 0; i<n; i++){
                if(curr + weights[i] > mid){
                    day++;
                    curr = 0;
                }
                curr = curr + weights[i];
            }
            if(day > days){
                maxw = mid +1;
            }else {
                totalw = mid;
            }
        }
        return maxw;
    }
};