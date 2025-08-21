class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0, j = s.size() - 1;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        
        for(int i = 0; i<s.size(); i++){
            string substr = "";
            substr += s[i];

            if(isPalindrome(substr)){
                count++;
            }

            for(int j = i+1; j<s.size(); j++){
                substr += s[j];
                if(isPalindrome(substr)){
                    count++;
                }
            }
        }

        return count;
    }
};