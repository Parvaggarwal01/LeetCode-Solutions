class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        int i = 0;
        while(i < s.length()){
            if(s[i] == '#'){
                if(!s1.empty()) s1.pop();
            }else{
                s1.push(s[i]);
            }
            i++;
        }

        int j = 0;
        while(j < t.length()){
            if(t[j] == '#'){
                if(!s2.empty()) s2.pop();
            }else{
                s2.push(t[j]);
            }
            j++;
        }

        while(!s1.empty() && !s2.empty()){
            if(s1.top() != s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }

        return s1.empty() && s2.empty();
    }
};
