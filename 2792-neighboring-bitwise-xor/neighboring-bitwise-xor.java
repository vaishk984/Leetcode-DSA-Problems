class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int n = derived.length;
        
        boolean validWithZero = isValid(derived, 0);
        
        boolean validWithOne = isValid(derived, 1);
        
        return validWithZero || validWithOne;
    }

    private boolean isValid(int[] derived, int startValue) {
        int n = derived.length;
        int[] original = new int[n];
        original[0] = startValue;

        for (int i = 1; i < n; i++) {
            original[i] = derived[i - 1] ^ original[i - 1];
        }

        // Check the condition for derived[n - 1]
        return (original[n - 1] ^ original[0]) == derived[n - 1];
    }
}