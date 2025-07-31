class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countOnes = 0;
        int maxOnes = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                countOnes++;
                maxOnes = max(countOnes, maxOnes);
            }else{
                countOnes = 0;
            }
        }

        return maxOnes;
    }
};