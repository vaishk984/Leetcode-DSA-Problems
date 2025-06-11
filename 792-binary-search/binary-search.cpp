class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int h){
        while(l<=h){
            int mid = l + (h - l)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]>target){
                return binarySearch(nums, target, l, mid - 1);
            }else{
                return binarySearch(nums, target, mid + 1, h);
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        return binarySearch(nums, target, l, h);
    }
};