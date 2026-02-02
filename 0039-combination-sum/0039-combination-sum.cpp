class Solution {
public:
    void helper(int i, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
        if(i == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }        
        if(arr[i] <= target){
            temp.push_back(arr[i]);
            helper(i, target-arr[i],arr, temp, ans);
            temp.pop_back();
        }
        helper(i+1, target, arr, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, target, candidates, temp, ans);
        return ans;
    }
};