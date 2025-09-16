class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int maxCount = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                count++;
                maxCount = max(count, maxCount);
            }else{
                count = 1;   
            }
        }

        return maxCount;
    }
};