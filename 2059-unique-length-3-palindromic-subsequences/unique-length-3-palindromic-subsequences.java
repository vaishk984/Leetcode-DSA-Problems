class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        int[] leftCount = new int[26];  // Count of characters to the left
        int[] rightCount = new int[26]; // Count of characters to the right

        // Populate rightCount with frequencies of all characters
        for (int i = 0; i < n; i++) {
            rightCount[s.charAt(i) - 'a']++;
        }

        // Use a set to store unique palindromes
        Set<String> uniquePalindromes = new HashSet<>();

        // Iterate through the string, fixing the middle character
        for (int i = 0; i < n; i++) {
            char middle = s.charAt(i);
            rightCount[middle - 'a']--;  // Remove the current character from rightCount

            // Check all possible 'a' characters for the palindrome pattern 'axa'
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (leftCount[ch - 'a'] > 0 && rightCount[ch - 'a'] > 0) {
                    uniquePalindromes.add(ch + "" + middle + ch);
                }
            }

            // Add the current character to leftCount
            leftCount[middle - 'a']++;
        }

        // Return the count of unique palindromes
        return uniquePalindromes.size();
    }
}