class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int minAbs = INT_MAX;
        int negCnt = 0;
        for(const auto& row : matrix){
            for(int val : row){
                total += abs(val);
                if(val < 0){
                    negCnt++;
                }
                minAbs = min(minAbs, abs(val));
            }
        }
        if(negCnt % 2 != 0){
            total -= 2LL * minAbs;
        }

        return total;
    }
};