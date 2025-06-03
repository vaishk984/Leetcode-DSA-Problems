class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        for(int i = 0; i<n-2; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            

            while(j<k){
                
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++;
                }else if(sum > 0 ){
                    k--;
                }else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    int leftVal = nums[j], rightVal = nums[k];
                    while (j < k && nums[j] == leftVal) j++;  // Skip duplicates
                    while (j < k && nums[k] == rightVal) k--;
                }
                
            }
        }


        return result;
    }
};