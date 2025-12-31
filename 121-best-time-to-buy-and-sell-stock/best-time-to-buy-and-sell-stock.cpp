class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int maxP = INT_MIN;

        for(int i = 0; i<prices.size(); i++){
            minP = min(minP, prices[i]);

            int profit = prices[i] - minP;

            maxP = max(maxP, profit);
        }

        return maxP;
    }
};