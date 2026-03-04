class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int total = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1){
                    bool row = true;
                    bool col = true;
                    for(int k = 0; k<m; k++){
                        if(k != j && mat[i][k] == 1){
                            row = false;
                        }
                    }
                    for(int l = 0; l<n; l++){
                        if(l != i && mat[l][j] == 1){
                            row = false;
                        }
                    }
                    if(row && col){
                        total += 1;
                    }
                }
            }
        }
        return total;
    }
};