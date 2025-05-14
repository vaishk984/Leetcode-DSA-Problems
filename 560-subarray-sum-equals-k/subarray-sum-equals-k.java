class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int sum = 0;

        HashMap<Integer, Integer> prefixMap = new HashMap<>();

        prefixMap.put(0, 1);

        for(int num: nums){
            sum += num;
            
            if(prefixMap.containsKey(sum-k)){
                count += prefixMap.get(sum-k);
            }

            prefixMap.put(sum, prefixMap.getOrDefault(sum, 0) + 1);
        }

        return count;
    }
}