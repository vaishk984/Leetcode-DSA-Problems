class Solution {
public:
    int maxEl(vector<int>& piles){
        int maxEl = INT_MIN;
        for(int i = 0; i<piles.size(); i++){
            maxEl = max(maxEl, piles[i]);
        }

        return maxEl;
    }

    long long hourly(vector<int>& piles, int hour){
        long long totalHrs = 0;
        for(int i = 0; i<piles.size(); i++){
            totalHrs += ceil(double(piles[i])/double(hour));
        }

        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxEl(piles);

        while(low<=high){
            int mid = low + (high - low)/2;

            long long totalHrs = hourly(piles, mid);

            if(totalHrs<=h){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};