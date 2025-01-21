class Solution {
    public long gridGame(int[][] grid) {
        
    int n = grid[0].length;
        long[] prefixTop = new long[n + 1];
        long[] prefixBottom = new long[n + 1];
        
        // Calculate prefix sums for the top and bottom rows
        for (int i = 0; i < n; i++) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }
        
        long result = Long.MAX_VALUE;
        
        // Evaluate the maximum points the second robot can collect
        for (int i = 0; i < n; i++) {
            long pointsIfTurnDownAtI = Math.max(prefixTop[n] - prefixTop[i + 1], prefixBottom[i]);
            result = Math.min(result, pointsIfTurnDownAtI);
        }
        
        return result;
    }
}