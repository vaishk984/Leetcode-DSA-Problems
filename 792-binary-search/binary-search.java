class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;

        int mid = (left+right)/2;

        for(int i = 0; i<nums.length; i++){
            if(nums[i]==target){
                return i;
            }

            else if(nums[i]<target){
                right = mid-1;
            }

            else{
                left = mid+1;
            }
        }

        return -1;
    }
}