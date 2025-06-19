class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>> result;
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            return (a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]));
        });

        for(int i = 0; i<people.size(); i++){
            int index = people[i][1];
            vector<int> person = people[i];
            result.insert(result.begin() + index, person);
        }

        return result;
    }
};