class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // directions for right, left, down, up
        int[][] cost = new int[m][n];
        
        // Initialize the cost matrix with a high value (infinity)
        for (int[] row : cost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Min-heap for Dijkstra's algorithm, stores (cost, x, y)
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        
        // Start from the top-left corner (0, 0)
        pq.offer(new int[] {0, 0, 0});
        cost[0][0] = 0;
        
        // Directions for moving in grid
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int c = curr[0], x = curr[1], y = curr[2];
            
            // If we reached the bottom-right corner, return the current cost
            if (x == m - 1 && y == n - 1) {
                return c;
            }
            
            // Try all four possible directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                
                // Check if the new position is valid
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    // Check if the direction matches the grid's sign at (x, y)
                    int newCost = c + (grid[x][y] == i + 1 ? 0 : 1); // 1-indexed direction matching
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        pq.offer(new int[] {newCost, nx, ny});
                    }
                }
            }
        }
        return -1; 
    }
}