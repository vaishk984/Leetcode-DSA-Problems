class Solution {
public:
    void getAllSubsets(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& allSubsets){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, i+1, ans, allSubsets);
        ans.pop_back();
        getAllSubsets(nums, i+1, ans, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, 0, ans, allSubsets);

        return allSubsets;
    }
};