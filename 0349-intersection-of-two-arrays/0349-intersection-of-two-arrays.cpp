class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1;
        unordered_map<int, int> n2;
        for(auto it: nums1){
            n1[it]++;
        }
        for(auto it: nums2){
            n2[it]++;
        }
        vector<int> res;
        for(auto it:n1){
            if(n2.count(it.first)){
                res.push_back(it.first);
            }
        }
        return res;
    }
};