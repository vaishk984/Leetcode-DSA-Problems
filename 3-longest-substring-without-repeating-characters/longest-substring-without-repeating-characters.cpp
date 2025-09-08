class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int i = 0, j = 0, maxLen=0;
        for(j = 0; j<s.size(); j++){
            while(set.find(s[j]) != set.end()){
                set.erase(s[i]);
                i++;
            }

            set.insert(s[j]);

            maxLen = max(maxLen, j-i+1);
        }

        return maxLen;
    }
};