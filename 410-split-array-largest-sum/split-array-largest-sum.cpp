class Solution {
public:
    bool isValid(vector<int>& nums, int n, int k, int mid){
        int sub = 1, sum = 0;

        for(int i = 0; i<n; i++){
            if(nums[i]>mid){
                return false;
            }

            if(sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                sub++;
                sum = nums[i];
            }
        }

        if(sub>k){
            return false;
        }else{
            return true;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;

        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }

        int st = 0, en = sum, ans = -1;

        while(st<=en){
            int mid = st + (en-st)/2;
            if(isValid(nums, n, k, mid)){
                ans = mid;
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }

        return ans;
    }
};