class Solution {
public:
    void helper(int sum, int last,vector<int>& temp,int k, vector<vector<int>>& ans){
        if(sum == 0 && k == temp.size()){
            ans.push_back(temp);
            return;
        }
        if(sum <= 0 && k < temp.size()){
            return;
        }

        for(int i=last; i<=9; i++){
            if(i <= sum){
                temp.push_back(i);
                helper(sum - i, i+1, temp, k, ans);
                temp.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(n, 1, temp, k, ans);
        return ans;
    }
};