class Solution {
public:
    int daysReq(vector<int>& weights, int capacity){
        int days = 1, load = 0;
        for(int i = 0; i<weights.size(); i++){
            if(weights[i]+load > capacity){
                days += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN, sum = 0;
        for(int i = 0; i<weights.size(); i++){
            maxi = max(maxi, weights[i]);
            sum+=weights[i];
        }

        int low = maxi, high = sum;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(daysReq(weights, mid)<=days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};