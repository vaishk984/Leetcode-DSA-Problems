class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        int result = 0;

        if (n2 % 2 != 0) {
            for (int num : nums1) {
                result ^= num;
            }
        }

        if (n1 % 2 != 0) {
            for (int num : nums2) {
                result ^= num;
            }
        }

        return result;
    }
}