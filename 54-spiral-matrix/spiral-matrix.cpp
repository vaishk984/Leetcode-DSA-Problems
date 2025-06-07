class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0, endRow = matrix.size()-1, startCol = 0, endCol = matrix[0].size()-1;
        vector<int> ans;
        
        while(startRow<=endRow && startCol<=endCol){
            //Top
            for(int j = startCol; j<=endCol; j++){
                ans.push_back(matrix[startRow][j]);
            }

            //Right
            for(int i = startRow+1; i<=endRow; i++){
                
                ans.push_back(matrix[i][endCol]);
            }

            //Bottom
            for(int j = endCol-1; j>=startCol; j--){
                if(startRow==endRow){
                    break;
                }
                ans.push_back(matrix[endRow][j]);
            }

            //Left
            for(int i = endRow-1; i>startRow; i--){
                if(startCol==endCol){
                    break;
                }
                ans.push_back(matrix[i][startCol]);
            }

            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        

        return ans;
    }
};