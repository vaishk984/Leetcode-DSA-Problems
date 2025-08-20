class Solution {
public:
    bool validPalindrome(string s) {
        int st = 0;
        int en = s.size() - 1;

        while(st<en){
            if(s[st] == s[en]){
                st++;
                en--;
            }else{
                if(isPalindrome(s, st+1, en)){
                    return true;
                }

                if(isPalindrome(s, st, en-1)){
                    return true;
                }

                return false;
            } 
        }

        return true;
    }

    bool isPalindrome(string &s, int st, int en){
        while(st<en){
            if(s[st] != s[en]){
                return false;
            }
            st++;
            en--;
        }

        return true;
    }
};