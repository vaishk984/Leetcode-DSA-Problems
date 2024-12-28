class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> s = new Stack<>();
        int nxtGreater[] = new int[nums.length];
        int n = nums.length;
        for(int i = 2*n - 1; i>=0; i--){
            int currIndex= i % n;

            while(!s.isEmpty() && nums[s.peek()]<=nums[currIndex]){
                s.pop();
            }

            if(s.isEmpty()){
                nxtGreater[currIndex] = -1;
            }
            else{
                nxtGreater[currIndex] = nums[s.peek()];
            }

            s.push(currIndex);
        }

        return nxtGreater;
    }
}