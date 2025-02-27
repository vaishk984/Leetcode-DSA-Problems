class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        Map<Integer, Integer> indexMap = new HashMap<>();
        Map<Integer, Integer> dp = new HashMap<>();
        int maxLen = 0;

        // Store array elements with their indices for quick lookup
        for (int i = 0; i < n; i++) {
            indexMap.put(arr[i], i);
        }

        // Iterate over all pairs (j, i) where j < i
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int a = arr[j], b = arr[i];
                int c = b - a; // The number we need to check in indexMap
                
                if (c < a && indexMap.containsKey(c)) {
                    int k = indexMap.get(c);
                    int key = k * n + j;
                    dp.put(j * n + i, dp.getOrDefault(key, 2) + 1);
                    maxLen = Math.max(maxLen, dp.get(j * n + i));
                } else {
                    dp.put(j * n + i, 2);
                }
            }
        }
        return maxLen >= 3 ? maxLen : 0;
    }
}