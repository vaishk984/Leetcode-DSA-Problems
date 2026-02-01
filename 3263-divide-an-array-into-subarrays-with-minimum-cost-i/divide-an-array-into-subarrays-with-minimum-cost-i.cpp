class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = 0;
        int minFirst = INT_MAX, minSecond = INT_MAX;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<minFirst){
                minSecond = minFirst;
                minFirst = nums[i];
            }else if(nums[i]<minSecond){
                minSecond = nums[i];
            }

        }

        return sum + nums[0] + minFirst + minSecond;
    }
};