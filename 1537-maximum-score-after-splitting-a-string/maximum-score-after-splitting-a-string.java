class Solution {
    public int maxScore(String s) {
        int maxScore = Integer.MIN_VALUE;
        int totalOnes = 0;
        int n = s.length();
        
        for(char c: s.toCharArray()){
            if(c=='1'){
                totalOnes++;
            }
        }

        int leftZeros = 0;
        int rightOnes = totalOnes;

        for(int i = 0; i<n-1; i++){
            if(s.charAt(i)=='0'){
                leftZeros++;
            }else{
                rightOnes--;
            }

            int currentScore = leftZeros + rightOnes;
            maxScore = Math.max(currentScore, maxScore);
        }

        return maxScore;
    }
}