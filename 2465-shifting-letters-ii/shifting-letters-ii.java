class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] diff = new int[n + 1]; // Difference array

        // Apply the shifts to the difference array
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) {
                diff[start] += 1; // Forward shift
                if (end + 1 < n) diff[end + 1] -= 1;
            } else {
                diff[start] -= 1; // Backward shift
                if (end + 1 < n) diff[end + 1] += 1;
            }
        }

        // Compute the net shifts using prefix sum
        int[] netShifts = new int[n];
        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += diff[i];
            netShifts[i] = cumulativeShift;
        }

        // Apply the shifts to the string
        char[] result = s.toCharArray();
        for (int i = 0; i < n; i++) {
            int shift = netShifts[i];
            // Normalize shift to the range [0, 26]
            int normalizedShift = (shift % 26 + 26) % 26;
            result[i] = (char) ((result[i] - 'a' + normalizedShift) % 26 + 'a');
        }

        return new String(result);
    }
}