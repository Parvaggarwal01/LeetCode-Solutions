class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row*col -1;
        int mid = start + end/2;

        while(start <= end){
            int ele = matrix[mid/col][mid%col];
            if(ele == target){
                return 1;
            }
            else if(ele > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return 0;
    }
};