class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        int n = s.length();
        for(int i = 0; i<n; i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i] <='Z') || (s[i]>='0' && s[i] <='9')){
                temp.push_back(s[i]);
            }
        }
        for(int i = 0; i<temp.length(); i++){
            temp[i] = tolower(temp[i]);
        }

        int start=0;
        int end = temp.length() - 1;
        while(start < end){
            if(temp[start] != temp[end]){
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }
};