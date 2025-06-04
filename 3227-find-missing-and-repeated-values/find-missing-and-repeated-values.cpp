class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> set;
        vector<int> ans;
        int a, b;
        int actual_sum = 0;
        int n = grid.size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                actual_sum += grid[i][j];
                if(set.find(grid[i][j]) != set.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }

                set.insert(grid[i][j]);
            }
        }

        int expected_sum = (n*n*(n*n + 1))/2;
        b = expected_sum  - actual_sum + a;
        ans.push_back(b);

        return ans;
    }
};
    