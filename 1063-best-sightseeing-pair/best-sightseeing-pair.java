class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int maxScore = 0; // Maximum score found so far
        int maxLeft = values[0]; // Represents values[i] + i for the left sightseeing spot

        for (int j = 1; j < values.length; j++) {
            // Calculate the score for the pair (i, j)
            maxScore = Math.max(maxScore, maxLeft + values[j] - j);

            // Update maxLeft to be the best value for future pairs
            maxLeft = Math.max(maxLeft, values[j] + j);
        }

        return maxScore;
    }
}