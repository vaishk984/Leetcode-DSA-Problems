class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxCount = 0, res = 0;
        vector<int> freq(26, 0);

        for(int right = 0; right<s.size(); right++){
            freq[s[right] - 'A']++;
            maxCount = max(freq[s[right] - 'A'], maxCount);

            while((right - left + 1) - maxCount > k){
                freq[s[left] - 'A']--;
                left++;
            }

            res = max(right - left + 1, res);
        }

        return res;
    }
};