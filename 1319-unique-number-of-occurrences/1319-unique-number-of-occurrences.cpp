class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(auto it:arr){
            map[it]++;
        }
        for(auto it:map){
            int count = 0;
            for(auto cp:map){
                if(cp.second == it.second){
                    count++;
                }
                if(count > 1){
                    return false;
                }
            }
            
        }
        return true;
        
    }
};