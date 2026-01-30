class Solution {
public:
    int maxSubarray(vector<int>& nums, int el){
        int cntSubarray = 1;
        long long sumSubarr = 0;

        for(int i = 0; i<nums.size(); i++){
            if(sumSubarr + nums[i] <= el){
                sumSubarr += nums[i];
            }else{
                sumSubarr = nums[i];
                cntSubarray++;
            }
        }

        return cntSubarray;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        int maxi = INT_MIN, sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        int low = maxi, high = sum;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(maxSubarray(nums, mid)>k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return low;
    }
};