class Solution {
public:
    int binarySearchRS(vector<int>& nums, int st, int en, int target){
        while(st<=en){
            int mid = st + (en - st)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[st]<=nums[mid]){
                if(target>=nums[st] && target<=nums[mid]){
                    return binarySearchRS(nums, st, mid-1, target);
                }else{
                    return binarySearchRS(nums, mid+1, en, target);
                }
            }else{
                if(target>=nums[mid] && target<=nums[en]){
                    return binarySearchRS(nums, mid+1, en, target);
                }else{
                    return binarySearchRS(nums, st, mid-1, target);
                }
            }
        }
        
        

        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearchRS(nums, 0, nums.size()-1, target);
    }
};