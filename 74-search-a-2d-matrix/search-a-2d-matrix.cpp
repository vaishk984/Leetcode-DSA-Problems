class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int start = 0, end = matrix[0].size()-1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(matrix[row][mid] == target){
                return true;
            }else if(matrix[row][mid]<target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int startRow = 0, endRow = m-1;

        while(startRow <= endRow){
            int midRow = startRow + (endRow-startRow)/2;

            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                return searchInRow(matrix, target, midRow);
            }else if(target>matrix[midRow][n-1]){
                startRow = midRow + 1;
            }else{
                endRow = midRow - 1;
            }
        }

        return false;
    }
};