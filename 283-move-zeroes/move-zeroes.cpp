class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = -1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                start++;
                nums[start] = nums[i];
            }
        }

        while(start<nums.size()-1){
            start++;
            nums[start] = 0;
        }
    }
};