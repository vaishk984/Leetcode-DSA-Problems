class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xr = 0;

        for(int i = 0; i<nums.size(); i++){
            xr = xr ^ nums[i];
            xr = xr ^ (i + 1);
        }

        int bitNo = 0;

        while(1){
            if((xr & (1 << bitNo)) != 0){
                break;
            }

            bitNo++;
        }

        int zero = 0, one = 0;
        for(int i = 0; i<nums.size(); i++){
            if((nums[i] & (1<<bitNo)) != 0){
                one = one ^ nums[i];
            }else{
                zero = zero ^ nums[i];
            }
        }

        for(int i = 1; i<=nums.size(); i++){
            if((i & (1<<bitNo)) != 0){
                one = one ^ i;
            }else{
                zero = zero ^ i;
            }
        }


        int cnt = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == zero){
                cnt++;
            }
        }

        if(cnt == 2){
            return {zero, one};
        }

        return {one, zero};
    }
};