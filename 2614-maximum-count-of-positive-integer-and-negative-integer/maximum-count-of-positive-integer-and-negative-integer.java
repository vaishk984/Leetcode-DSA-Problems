class Solution {
    public int maximumCount(int[] nums) {
        int posCount = 0;
        int negCount = 0;
        for (int num : nums) {
            if (num > 0) {
                posCount++;
            } else if (num < 0) {
                negCount++;
            }
        }
        return Math.max(posCount, negCount);
    }
}