class Solution {
    public int numWays(String[] words, String target) {
        int mod = 1_000_000_007;
        int m = target.length();
        int n = words[0].length();

        // Step 1: Precompute the frequency of each character at each index across words
        int[][] freq = new int[26][n];
        for (String word : words) {
            for (int j = 0; j < n; j++) {
                freq[word.charAt(j) - 'a'][j]++;
            }
        }

        // Step 2: Dynamic Programming Array
        // dp[i][j] = ways to form target[0:i] using words[0:j]
        long[][] dp = new long[m + 1][n + 1];
        
        // Base Case: There is exactly one way to form an empty prefix of the target
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }

        // Step 3: Populate DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Option 1: Skip the current column
                dp[i][j] = dp[i][j - 1];

                // Option 2: Use the current column if the character matches
                char targetChar = target.charAt(i - 1);
                if (freq[targetChar - 'a'][j - 1] > 0) {
                    dp[i][j] += dp[i - 1][j - 1] * freq[targetChar - 'a'][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }

        // The answer is the number of ways to form the full target using all columns
        return (int) dp[m][n];
    }
}