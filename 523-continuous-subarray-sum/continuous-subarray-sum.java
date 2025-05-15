class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1); // Important base case for when subarray starts at index 0

        int sum = 0;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            int mod = k == 0 ? sum : sum % k;

            if (map.containsKey(mod)) {
                if (i - map.get(mod) >= 2) {
                    return true; // Subarray size is at least 2
                }
            } else {
                map.put(mod, i); // Only store the first occurrence
            }
        }

        return false;
    }
}