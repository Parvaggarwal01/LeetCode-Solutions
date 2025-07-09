class Solution {
public:
    void generate(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);
        for(int i = index; i<nums.size(); i++){
            curr.push_back(nums[i]);
            generate(i+1, nums, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        generate(0, nums, curr, res);
        return res;
    }
};