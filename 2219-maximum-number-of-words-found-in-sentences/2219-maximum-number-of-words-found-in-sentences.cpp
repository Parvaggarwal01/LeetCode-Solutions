class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int maxi = 0;
        string temp ="";
        for(int i = 0; i<sentences.size(); i++){
            int count = 0;
            temp = sentences[i];
            for(int j = 0; j<temp.length(); j++){
                if(temp[j] == ' '){
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi+1;
    }
};