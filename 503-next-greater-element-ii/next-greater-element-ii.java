class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> s = new Stack<>();
        int nxtGreater[] = new int[nums.length];

        for(int i = 2*(nums.length-1); i>=0; i--){
            int currentIndex = i % nums.length;
            while(!s.isEmpty() && nums[s.peek()]<=nums[currentIndex]){
                s.pop();
            }

            if(s.isEmpty()){
                nxtGreater[currentIndex] = -1;
            }
            else{
                nxtGreater[currentIndex] = nums[s.peek()];
            }

            s.push(currentIndex);
        }

        return nxtGreater;
    }
}