class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        
        Map<Integer, Integer> ballToColor = new HashMap<>(); // Ball -> Color
        Map<Integer, Integer> colorCount = new HashMap<>();  // Color -> Count
        int[] result = new int[queries.length];
        int distinctColors = 0;

        for (int i = 0; i < queries.length; i++) {
            int ball = queries[i][0];
            int newColor = queries[i][1];

            // If ball was previously colored
            if (ballToColor.containsKey(ball)) {
                int oldColor = ballToColor.get(ball);
                colorCount.put(oldColor, colorCount.get(oldColor) - 1);
                
                // If old color count becomes 0, remove it from distinct colors
                if (colorCount.get(oldColor) == 0) {
                    colorCount.remove(oldColor);
                    distinctColors--;
                }
            }

            // Assign new color to ball
            ballToColor.put(ball, newColor);
            colorCount.put(newColor, colorCount.getOrDefault(newColor, 0) + 1);
            
            // If this is a new color, increase distinct count
            if (colorCount.get(newColor) == 1) {
                distinctColors++;
            }

            // Store result
            result[i] = distinctColors;
        }

        return result;
    }
}