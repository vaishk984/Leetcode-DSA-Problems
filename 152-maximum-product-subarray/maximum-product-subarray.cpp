class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffix = 1;
        int prefix = 1;
        int maxProd = INT_MIN;
        int n = nums.size();

        for(int i = 0; i<nums.size(); i++){
            if(prefix==0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-i-1];

            maxProd = max(maxProd, max(suffix, prefix));
        }

        return maxProd;
    }
};