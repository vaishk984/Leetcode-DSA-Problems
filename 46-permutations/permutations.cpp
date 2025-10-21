class Solution {
public:
    void allPermutations(vector<int>& nums, int idx, vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            allPermutations(nums, idx+1, ans);
            swap(nums[idx], nums[i]);   //Backtracking step
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        allPermutations(nums, 0, ans);

        return ans;
    }
};