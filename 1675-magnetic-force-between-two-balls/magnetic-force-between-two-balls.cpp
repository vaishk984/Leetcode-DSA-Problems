class Solution {
public:
    bool canWePlace(vector<int>& position, int dist, int m){
        int cntBalls = 1, lastBall = position[0];

        for(int i = 1; i<position.size(); i++){
            if((position[i] - lastBall) >= dist){
                cntBalls += 1;
                lastBall = position[i];
            }
        }

        if(cntBalls>=m){
            return true;
        }else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        int maxi = INT_MIN, mini = INT_MAX;

        sort(position.begin(), position.end());

        for(int i = 0; i<position.size(); i++){
            maxi = max(position[i], maxi);
            mini = min(position[i], mini);
        }

        int low = 1, high = maxi - mini;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(canWePlace(position, mid, m)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return high;
    }
};