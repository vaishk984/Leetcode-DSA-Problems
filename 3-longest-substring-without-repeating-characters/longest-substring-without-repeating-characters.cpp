class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, res = 0;
        vector<int> freq(128, 0);

        for(int right = 0; right<s.size(); right++){
            freq[s[right]]++;
            
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            res = max(right-left+1, res);
        }

        return res;
    }
};