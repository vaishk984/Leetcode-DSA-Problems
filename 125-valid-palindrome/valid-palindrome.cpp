class Solution {
public:
    string checkAlphaNum(string s){
        string str = "";

        for(char c : s){
            if(isalnum(c)){
                str += tolower(c);
            }   
        }

        return str;
    }
    
    bool isPalindrome(string s) {
        string str = checkAlphaNum(s);

        int i = 0, j = str.size() - 1;

        while(i<=j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};