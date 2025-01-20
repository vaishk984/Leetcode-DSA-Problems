class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, int[]> positionMap = new HashMap<>();
        
        // Map each matrix value to its coordinates
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positionMap.put(mat[i][j], new int[]{i, j});
            }
        }
        
        int[] rowPaintCount = new int[m];
        int[] colPaintCount = new int[n];
        
        // Process the painting sequence
        for (int k = 0; k < arr.length; k++) {
            int[] pos = positionMap.get(arr[k]);
            int row = pos[0], col = pos[1];
            
            rowPaintCount[row]++;
            colPaintCount[col]++;
            
            // Check if the current row or column is fully painted
            if (rowPaintCount[row] == n || colPaintCount[col] == m) {
                return k;
            }
        }

        return -1;
    }
}