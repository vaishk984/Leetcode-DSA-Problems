class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxLen = 0;
        unordered_set<int> set;
        for(int j = 0; j<s.size(); j++){
            while(set.find(s[j]) != set.end()){
                set.erase(s[i]);
                i++;
            }

            set.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};