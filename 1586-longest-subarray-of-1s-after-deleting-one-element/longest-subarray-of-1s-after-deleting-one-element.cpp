class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int L = 0, zeroes = 0, res = 0;

        for(int R = 0; R<nums.size(); R++){
            if(nums[R] == 0){
                zeroes++;
            }

            while(zeroes>1){
                if(nums[L] == 0) zeroes--;
                L++;
            }

            res = max(res, R - L);
        }

        return res;
    }
};