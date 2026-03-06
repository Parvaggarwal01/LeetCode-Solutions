class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int ans = false;
        for(int i = 0; i<n; i++){
            if(s[i]=='0'){
                ans = true;
            }else if(ans){
                return false;
            }
        }
        return true;
    }
};