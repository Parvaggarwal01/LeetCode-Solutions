class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i<s.length(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i] <='Z') || (s[i]>='0' && s[i] <='9')){
                temp.push_back(s[i]);
            }
        }
        for(int i = 0; i<temp.length(); i++){
            temp[i] = tolower(temp[i]);
        }

        int st = 0;
        int e = temp.length() - 1;
        while(st < e){
            if(temp[st] != temp[e]){
                return false;
            }else {
                st++;
                e--;
            }
            
        }
        return true;
    }
};