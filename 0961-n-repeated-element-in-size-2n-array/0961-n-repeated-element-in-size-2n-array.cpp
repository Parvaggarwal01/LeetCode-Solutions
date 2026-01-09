class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int l = nums.size();
        int n = l/2;
        map<int, int> mp;
        for(int i = 0; i<l; i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second == n){
                return it.first;
            }
        }
        return 0;
    }
};