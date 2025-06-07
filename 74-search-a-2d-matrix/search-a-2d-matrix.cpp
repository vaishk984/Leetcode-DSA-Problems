class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int startRow = 0, endCol = n-1;

        while(startRow<m && endCol>=0){
            if(matrix[startRow][endCol]==target){
                return true;
            }else if(matrix[startRow][endCol]<target){
                startRow++;
            }else{
                endCol--;
            }
        }

        return false;
    }
};