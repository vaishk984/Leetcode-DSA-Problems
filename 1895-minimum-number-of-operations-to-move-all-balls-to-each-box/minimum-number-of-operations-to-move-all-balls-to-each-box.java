class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int result[] = new int[n];

        int leftOnes = 0;
        int operationsToLeft = 0;

        for(int i = 0; i<n; i++){
            result[i] += operationsToLeft;
            leftOnes += boxes.charAt(i) == '1' ? 1 : 0;
            operationsToLeft += leftOnes;
        }

        int rightOnes = 0;
        int operationsToRight = 0;

        for(int i = n-1; i>=0; i--){
            result[i] += operationsToRight;
            rightOnes += boxes.charAt(i) == '1' ? 1 : 0;
            operationsToRight += rightOnes;
        }

        return result;
    }
}