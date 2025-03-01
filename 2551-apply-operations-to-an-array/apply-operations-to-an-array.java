class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;

        // Step 1: Process adjacent equal elements
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move zeros to the end (Two-pointer approach)
        int write = 0; // Position to write non-zero values

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[write++] = nums[i];
            }
        }

        // Fill remaining elements with zero
        while (write < n) {
            nums[write++] = 0;
        }

        return nums;
    }
}