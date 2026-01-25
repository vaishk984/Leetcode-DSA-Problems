class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int pre = 1, suff = 1;

        for(int i = 0; i<nums.size(); i++){
            if(pre == 0) pre = 1;
            pre *= nums[i];
            maxProd = max(pre, maxProd);
        }

        for(int i = nums.size() - 1; i>=0; i--){
            if(suff == 0) suff = 1;
            suff *= nums[i];
            maxProd = max(suff, maxProd);
        }

        return maxProd;
    }
};