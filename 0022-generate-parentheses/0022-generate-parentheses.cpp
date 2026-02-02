class Solution {
public:
    void back(string curr, int open, int close, int n, vector<string> &res){
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            back(curr + "(", open+1, close, n, res);
        }
        if(open > close){
            back(curr + ")", open, close+1, n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        back("", 0, 0, n, res);
        return res;
    }
};