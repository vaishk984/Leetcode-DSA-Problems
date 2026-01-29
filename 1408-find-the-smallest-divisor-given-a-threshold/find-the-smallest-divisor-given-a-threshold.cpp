class Solution {
public:
    int sumOfDivisors(vector<int>& nums, int val){
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)val);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        int low = 1, high = maxi;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(sumOfDivisors(nums, mid)<=threshold){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};