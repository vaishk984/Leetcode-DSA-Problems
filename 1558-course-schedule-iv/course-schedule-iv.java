class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        // Step 1: Initialize isPrerequisite matrix
        boolean[][] isPrerequisite = new boolean[n][n];
        
        // Step 2: Mark direct prerequisites
        for (int[] prereq : prerequisites) {
            isPrerequisite[prereq[0]][prereq[1]] = true;
        }
        
        // Step 3: Compute transitive closure using Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    isPrerequisite[i][j] = isPrerequisite[i][j] || 
                                           (isPrerequisite[i][k] && isPrerequisite[k][j]);
                }
            }
        }
        
        // Step 4: Answer the queries
        List<Boolean> result = new ArrayList<>();
        for (int[] query : queries) {
            result.add(isPrerequisite[query[0]][query[1]]);
        }
        
        return result;
    }
}