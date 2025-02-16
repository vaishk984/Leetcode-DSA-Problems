class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[] = new int[2];

        HashMap<Integer, Integer> map = new HashMap<>();

        ans[0] = ans[1] = -1;

        for(int i = 0; i<nums.length; i++){
            int needed = target - nums[i];
            if(map.containsKey(needed)){
                ans[0] = map.get(needed);
                ans[1] = i;
                return ans;
            }
            map.put(nums[i], i);
        }

        return ans;
        
    }
}