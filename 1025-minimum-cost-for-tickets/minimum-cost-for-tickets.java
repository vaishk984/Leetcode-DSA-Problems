class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        HashSet<Integer> travelDays = new HashSet<>();
        for (int day : days) {
            travelDays.add(day);
        }

        // DP array to store the minimum cost up to each day
        int[] dp = new int[366]; // Day range is 1 to 365

        for (int i = 1; i <= 365; i++) {
            if (!travelDays.contains(i)) {
                // If it's not a travel day, no extra cost
                dp[i] = dp[i - 1];
            } else {
                // Calculate the cost for each ticket type
                int cost1Day = dp[i - 1] + costs[0];
                int cost7Day = dp[Math.max(0, i - 7)] + costs[1];
                int cost30Day = dp[Math.max(0, i - 30)] + costs[2];
                // Take the minimum of the three
                dp[i] = Math.min(cost1Day, Math.min(cost7Day, cost30Day));
            }
        }

        return dp[365];
    }
}