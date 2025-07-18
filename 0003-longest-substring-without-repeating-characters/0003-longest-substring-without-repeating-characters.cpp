class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int count = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(mp.count(s[i]) == 0 || mp[s[i]] < count){
            mp[s[i]] = i;
            ans = max(ans, i-count+1);
            }else{
                count = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};