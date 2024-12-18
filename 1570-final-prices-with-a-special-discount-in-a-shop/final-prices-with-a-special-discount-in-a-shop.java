class Solution {
    public int[] finalPrices(int[] prices) {
        int discount[] = new int[prices.length];

        for(int i = 0; i<prices.length; i++){
            discount[i] = prices[i];
            for(int j = i + 1; j<prices.length; j++){
                if(prices[j]<=prices[i]){
                    discount[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return discount;
    }
}