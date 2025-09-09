class Solution {
public:
    string reverseWords(string s) {
        int startOfWord = 0;

        for(int i = 0; i<=s.size(); i++){
            if(s[i]==' ' || i==s.size()){
                reverse(s.begin() + startOfWord, s.begin() + i);
                startOfWord = i+1;
            }
        }

        return s;
    }
};