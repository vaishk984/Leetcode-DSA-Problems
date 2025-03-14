class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;
        int left = 0, right = m + 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (canTransformToZeroArray(nums, queries, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left > m ? -1 : left;
    }

    private boolean canTransformToZeroArray(int[] nums, int[][] queries, int k) {
        int n = nums.length;
        int[] diff = new int[n + 1];
        
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) {
                diff[r + 1] -= val;
            }
        }
        
        int currentDecrement = 0;
        for (int i = 0; i < n; i++) {
            currentDecrement += diff[i];
            if (nums[i] > currentDecrement) {
                return false;
            }
        }
        
        return true;
    }
}