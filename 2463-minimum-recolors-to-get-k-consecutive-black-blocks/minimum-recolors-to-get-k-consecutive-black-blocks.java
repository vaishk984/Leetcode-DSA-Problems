class Solution {
    public int minimumRecolors(String blocks, int k) {
        int minRecolors = Integer.MAX_VALUE;
        int whiteCount = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                whiteCount++;
            }
        }
        minRecolors = whiteCount;

        // Slide the window through the string
        for (int i = k; i < blocks.length(); i++) {
            // Remove the leftmost character from the previous window
            if (blocks.charAt(i - k) == 'W') {
                whiteCount--;
            }
            // Add the new rightmost character to the current window
            if (blocks.charAt(i) == 'W') {
                whiteCount++;
            }
            // Update minimum recolors required
            minRecolors = Math.min(minRecolors, whiteCount);
        }

        return minRecolors;
    }
}