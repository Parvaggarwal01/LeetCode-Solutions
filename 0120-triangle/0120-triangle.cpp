class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < arr[i].size(); j++) {
                arr[i][j] += min(arr[i+1][j], arr[i+1][j+1]);
            }
        }
        return arr[0][0];
    }
};
