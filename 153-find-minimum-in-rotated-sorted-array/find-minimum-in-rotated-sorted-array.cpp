class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size()-1, ans = INT_MAX;

        while(st<=end){
            int mid = st + (end - st)/2;

            if(nums[st]<=nums[end]){
                ans = min(ans, nums[st]);
                break;
            }

            if(nums[st]<=nums[mid]){
                ans = min(ans, nums[st]);
                st = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }

        return ans;
    }
};