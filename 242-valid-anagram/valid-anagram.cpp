class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        if(s.length() != t.length()){
            return false;
        }

        for(char ch: s){
            freq[ch]++;
        }

        for(char ch: t){
            freq[ch]--;

            if(freq[ch]<0){
                return false;
            }
        }

        return true;
    }
};