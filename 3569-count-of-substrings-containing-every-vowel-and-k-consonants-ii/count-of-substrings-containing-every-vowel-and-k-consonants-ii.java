class Solution {
    public long countOfSubstrings(String word, int k) {
        return substringsWithAtMost(word, k) - substringsWithAtMost(word, k - 1);
    }

    private long substringsWithAtMost(String word, int k) {
        if (k < 0) return 0;

        long count = 0;
        int vowelCount = 0;
        int uniqueVowelCount = 0;
        Map<Character, Integer> vowelLastSeen = new HashMap<>();
        int left = 0;

        for (int right = 0; right < word.length(); ++right) {
            char currentChar = word.charAt(right);
            if (isVowel(currentChar)) {
                vowelCount++;
                if (!vowelLastSeen.containsKey(currentChar) || vowelLastSeen.get(currentChar) < left) {
                    uniqueVowelCount++;
                }
                vowelLastSeen.put(currentChar, right);
            }

            while (right - left + 1 - vowelCount > k) {
                char leftChar = word.charAt(left);
                if (isVowel(leftChar)) {
                    vowelCount--;
                    if (vowelLastSeen.get(leftChar) == left) {
                        uniqueVowelCount--;
                    }
                }
                left++;
            }

            if (uniqueVowelCount == 5) {
                int minLastSeen = Integer.MAX_VALUE;
                for (char vowel : "aeiou".toCharArray()) {
                    minLastSeen = Math.min(minLastSeen, vowelLastSeen.get(vowel));
                }
                count += minLastSeen - left + 1;
            }
        }

        return count;
    }

    private boolean isVowel(char c) {
        return "aeiou".indexOf(c) != -1;
    }
}