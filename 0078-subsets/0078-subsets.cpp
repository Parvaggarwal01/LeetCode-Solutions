class Solution {
public:
    void generate(int i, vector<int>& nums, vector<int> curr, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(curr);
            return;
        }

        
        generate(i+1, nums, curr, res);

        curr.push_back(nums[i]);
        generate(i+1, nums, curr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        generate(0, nums, curr, res);
        return res;
    }
};