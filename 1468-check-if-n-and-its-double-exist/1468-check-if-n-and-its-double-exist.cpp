class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;
        for(auto it:arr){
            map[it]++;
        }
        for(int i = 0; i<arr.size(); i++){
            int val = arr[i];
            if(val == 0){
                if(map[val] > 1){
                    return true;
                }
            }

            else if(map.count(val*2)){
                return true;
            }
        }
        return false;
    }
};