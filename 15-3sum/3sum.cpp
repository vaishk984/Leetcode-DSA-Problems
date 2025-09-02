class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1, right = nums.size() - 1;
            
            while(left<right){
                int triplet = nums[i] + nums[left] + nums[right];
                if(triplet == 0){
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left<right && nums[left] == nums[left-1]) left++;
                    while(left<right && nums[right] == nums[right+1]) right--;
                    
                }else if(triplet<0){
                    left++;
                }else{
                    right--;
                }
            }
            
        } 

        return triplets;
    }
};