class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        string temp = "";
        int n = sentences.size();
        for(int i=0; i<n; i++){
            int cnt = 0;
            temp = sentences[i];
            for(int j=0; j<temp.length(); j++){
                if(temp[j] == ' '){
                    cnt++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi+1;
    }
};