class Solution {
public:

    int lowerBound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1, ans = nums.size();

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(lowerBound(nums, target) == nums.size() || nums[lowerBound(nums, target)] != target){
            return {-1, -1};
        }

        return {lowerBound(nums, target), upperBound(nums, target) - 1};
    }
};