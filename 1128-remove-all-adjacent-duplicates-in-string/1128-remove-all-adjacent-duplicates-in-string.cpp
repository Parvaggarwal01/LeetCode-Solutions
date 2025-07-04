class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> s1;
        int i = 0;
        while(i < s.length()){
            if(!s1.empty() && s1.top() == s[i]){
                s1.pop();
            }else{
                s1.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};