class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int maxlen=0, l=0;
        for(int i = 0; i<fruits.size(); i++){
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[l]]--;
                if(m[fruits[l]] == 0){
                    m.erase(fruits[l]);
                }
                l++;
            }
            maxlen = max(maxlen,i-l+1);
        }
        return maxlen;
    }
};