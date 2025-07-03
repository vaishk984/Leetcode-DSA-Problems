class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string newStr(s.size(), ' ');
        for(int i = 0; i<s.size(); i++){
            newStr[indices[i]] = s[i];
        }

        return newStr;
    }
};