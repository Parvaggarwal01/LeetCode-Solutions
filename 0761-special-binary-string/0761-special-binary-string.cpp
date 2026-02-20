class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> group = {};
        int balance = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            balance += (s[i] == '1') ? 1 : -1;
            if (balance == 0){
                group.push_back(
                    '1'+
                    makeLargestSpecial(s.substr(start+1, i - start -1)) +
                    '0');
                start = i + 1;
            }
        }

        sort(group.begin(), group.end(), greater<string>());
        string ans;
        for (const auto& e : group) {
            ans += e;
        }
        return ans;
    }
};