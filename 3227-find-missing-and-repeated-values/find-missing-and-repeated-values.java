class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int nSquared = n * n;
        int[] count = new int[nSquared + 1];

        // Count occurrences of each number in the grid
        for (int[] row : grid) {
            for (int num : row) {
                count[num]++;
            }
        }

        int repeated = -1;
        int missing = -1;

        // Identify the repeated and missing numbers
        for (int i = 1; i <= nSquared; i++) {
            if (count[i] == 2) {
                repeated = i;
            } else if (count[i] == 0) {
                missing = i;
            }
        }

        return new int[]{repeated, missing};
    }
}