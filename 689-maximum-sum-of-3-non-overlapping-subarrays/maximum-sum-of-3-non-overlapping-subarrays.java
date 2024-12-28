import java.util.Arrays;

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;

        // Step 1: Compute the window sums
        int[] windowSums = new int[n - k + 1];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k - 1) {
                windowSums[i - k + 1] = sum;
                sum -= nums[i - k + 1];
            }
        }

        // Step 2: Compute the left and right max indices
        int[] left = new int[windowSums.length];
        int[] right = new int[windowSums.length];

        // Fill left array
        int maxIndex = 0;
        for (int i = 0; i < windowSums.length; i++) {
            if (windowSums[i] > windowSums[maxIndex]) {
                maxIndex = i;
            }
            left[i] = maxIndex;
        }

        // Fill right array
        maxIndex = windowSums.length - 1;
        for (int i = windowSums.length - 1; i >= 0; i--) {
            if (windowSums[i] >= windowSums[maxIndex]) {
                maxIndex = i;
            }
            right[i] = maxIndex;
        }

        // Step 3: Find the maximum sum of three subarrays
        int[] result = new int[3];
        int maxSum = 0;

        for (int mid = k; mid < windowSums.length - k; mid++) {
            int leftIndex = left[mid - k];
            int rightIndex = right[mid + k];

            int totalSum = windowSums[leftIndex] + windowSums[mid] + windowSums[rightIndex];

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result[0] = leftIndex;
                result[1] = mid;
                result[2] = rightIndex;
            }
        }
        

        return result;
    }
}