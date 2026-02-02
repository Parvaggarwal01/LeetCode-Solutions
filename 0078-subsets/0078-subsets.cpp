class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        helper(index+1, nums, curr, res);

        curr.pop_back();
        helper(index+1, nums, curr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(0, nums, curr, res);
        return res;
    }
};