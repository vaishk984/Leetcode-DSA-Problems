class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startRow = 0, endCol = matrix[0].size() - 1;
        while(startRow<matrix.size() && endCol>=0){
            if(matrix[startRow][endCol] == target){
                return true;
            }else if(matrix[startRow][endCol] < target){
                startRow++;
            }else{
                endCol--;
            }
        }

        return false;
    }
};