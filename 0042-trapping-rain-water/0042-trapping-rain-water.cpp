class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
       vector<int> left; 
       vector<int> right;
       int maxi = 0;
       for(int i = 0; i<n; i++){
        maxi = max(maxi, height[i]);
        right.push_back(maxi);
       } 
        maxi = 0;
       for(int i = n-1; i>=0; i--){
        maxi = max(maxi, height[i]);
        left.push_back(maxi);
       } 

       reverse(left.begin(), left.end());
        int sum = 0;
       for(int i = 0; i<n; i++){
        int ans = min(left[i],right[i]) - height[i];
        sum = sum + ans;
       }

       return sum;
    }
};