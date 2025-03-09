class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int count = 0;
        int alternating = 1;

        for (int i = 1; i < 2 * n; i++) {
            if (colors[i % n] == colors[(i - 1) % n]) {
                alternating = 1;
            } else {
                alternating++;
            }
            if (i >= n && alternating >= k) {
                count++;
            }
        }

        return count;
    }
}