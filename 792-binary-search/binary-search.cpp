class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int h, int target){
        while(l<=h){
            int mid = l + (h-l)/2;

            if(nums[mid] == target){
                return mid;
            }else if (nums[mid]>target){
                return binarySearch(nums, l, mid-1, target);
            }else{
                return binarySearch(nums, mid+1, h, target);
            }
        }
        
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        return binarySearch(nums, l, h, target);
    }
};