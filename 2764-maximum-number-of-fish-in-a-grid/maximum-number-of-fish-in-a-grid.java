class Solution {
    public int findMaxFish(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        int maxFish = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) { // Start DFS if the cell has fish and is not visited
                    maxFish = Math.max(maxFish, dfs(grid, visited, i, j));
                }
            }
        }

        return maxFish;
    }
        
    private int dfs(int[][] grid, boolean[][] visited, int i, int j) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Check for out-of-bounds or invalid cells
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] <= 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = true; // Mark cell as visited
        int fishCount = grid[i][j]; // Collect fish from the current cell

        // Directions for moving up, down, left, right
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Explore all 4 directions
        for (int[] dir : directions) {
            int newRow = i + dir[0];
            int newCol = j + dir[1];
            fishCount += dfs(grid, visited, newRow, newCol);
        }

        return fishCount;
    }
}