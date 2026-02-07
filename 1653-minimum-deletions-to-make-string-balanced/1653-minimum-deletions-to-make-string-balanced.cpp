class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        int del = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'b'){
                cnt++;
            }else{
                del = min(del + 1, cnt);
            }
        }
        return del;
    }
};