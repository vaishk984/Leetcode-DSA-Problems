class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0)ele=nums[i];
            count+=(ele==nums[i])?1:-1;
        }
        return ele;
    }
};