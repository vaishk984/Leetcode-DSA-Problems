class Solution {
public:
    bool isIncreasing(vector<int>& nums, int start, int end){
        for(int i = start; i<end; i++){
            if(nums[i+1]<=nums[i]){
                return false;
            }
        }

        return true;
    }

    bool isDecreasing(vector<int>& nums, int start, int end){
        for(int i = start; i<end; i++){
            if(nums[i]<=nums[i+1]){
                return false;
            }
        }

        return true;
    }
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        for (int p = 1; p < n - 2; p++) {
            for (int q = p + 1; q < n - 1; q++) {
                if (isIncreasing(nums, 0, p) &&
                    isDecreasing(nums, p, q) &&
                    isIncreasing(nums, q, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};