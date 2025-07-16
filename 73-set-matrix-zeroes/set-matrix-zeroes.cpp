class Solution {
public:
    vector<vector<int>> zeroMatrix(vector<vector<int>>& matrix, int n, int m){
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(row[i] == 1 || col[j]== 1){
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        zeroMatrix(matrix, n, m);
        
    }
};