class Solution {
public:
    string addBinary(string a, string b) {
       int n = a.length();
       int m = b.length();

       int carry = 0;
       string ans = "";

       int i = n - 1;
       int j = m - 1;

       while(i >= 0 || j >= 0 || carry){
        int bitA = (i >= 0) ? a[i] - '0' : 0;
        int bitB = (j >= 0) ? b[j] - '0' : 0;

        int sum = bitA ^ bitB ^ carry;

        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);

        ans.push_back(sum + '0');

        i--;
        j--;
       } 

       reverse(ans.begin(), ans.end());
       return ans;
    }
};