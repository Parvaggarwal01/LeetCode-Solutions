class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map;
        int n = arr.size();
        for(auto it:arr){
            map[it]++;
        }
        int maxi = -1;
        for(auto it:map){
            if(it.first == it.second){
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
};