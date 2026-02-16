class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxi = 0;
        
        for(int i = 0; i<n; i++){
            if(height[i] > maxi){
                maxi = height[i];
            }
            left[i] = maxi;
        }
        maxi = 0;
        for(int j = n-1; j>=0; j--){
            if(height[j] > maxi){
                maxi = height[j];
            }
            right[j] = maxi;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};