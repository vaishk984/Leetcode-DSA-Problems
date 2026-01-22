class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int prefixSum = 0, cnt = 0;
        mpp[0] = 1;

        for(int i = 0; i<nums.size(); i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            cnt += mpp[remove];
            mpp[prefixSum] += 1;
        }

        return cnt;
    }
};