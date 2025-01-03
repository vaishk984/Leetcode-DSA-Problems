class Solution {
    public int waysToSplitArray(int[] nums) {
        int validSplits = 0;
        long sum = 0;
        for(int i = 0; i<nums.length; i++){
            sum+=nums[i];
        }

        long leftSum = 0;

        for(int i = 0; i<nums.length-1; i++){
            leftSum += nums[i];
            long rightSum = sum - leftSum;
            if(leftSum>=rightSum){
                validSplits++;
            }
        }

        return validSplits;
    }
}