class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder unique = new StringBuilder();
        
        for (int i = 0; i < nums.length; i++) {
            // Flip the i-th bit of the i-th string
            unique.append(nums[i].charAt(i) == '0' ? '1' : '0');
        }
        
        return unique.toString();
    }
}