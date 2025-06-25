class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right<s.size(); right++){
            while(set.find(s[right]) != set.end()){
                set.erase(s[left]); //shrink the window
                left++; 
            }

            set.insert(s[right]);  //expand the window
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};