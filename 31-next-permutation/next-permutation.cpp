class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1;
        int n = nums.size();

        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                piv = i;
                break;
            }
        }

        if(piv==-1){
            int i = 0, j = nums.size() - 1;
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i>piv; i--){
            if(nums[i]>nums[piv]){
                swap(nums[i], nums[piv]);
                break;
            }
        }

        int i = piv + 1;
        int j = n - 1;

        while(i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

    }
};