class Solution {
    public int searchInsert(int[] nums, int target) {
        
    int st = 0;
        int en = nums.length - 1;
        while(st <= en) {
            int mid = st + (en - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                en = mid - 1;
            } else { 
                st = mid + 1;
            }
        }
        return st; 
    } 
    
}