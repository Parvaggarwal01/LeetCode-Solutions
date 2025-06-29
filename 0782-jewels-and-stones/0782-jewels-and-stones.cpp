class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> map;
        for(auto it:stones){
            map[it]++;
        }
        int count = 0;
        for(auto jewel:jewels){
            if(map.count(jewel)){
                count += map[jewel];
            }
        }
        return count;
    }
};