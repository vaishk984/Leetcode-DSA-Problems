class Solution {
public:
    bool isPalindrome(const string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        string new_str = "";
        
        for(char c: s){ 
            if (isalnum(c)) {
                new_str += tolower(c);
            }
        }

        int i = 0;
        int j = new_str.size()-1;
        while(i<j){
            if(new_str[i]!=new_str[j]){
                return isPalindrome(new_str, i+1, j) || isPalindrome(new_str, i, j-1);
            }
            i++;
            j--;
        }

        return true;
    }
};