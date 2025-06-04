class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do{
            slow = nums[slow]; //slow + 1
            fast = nums[nums[fast]];  //fast + 2
        }while(slow != fast);

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};