class Solution {
public:
    string toLowerCase(string s) {
        string lower;
        for(int i = 0; i<s.size(); i++){
            lower += tolower(s[i]);
        }

        return lower;
    }
};