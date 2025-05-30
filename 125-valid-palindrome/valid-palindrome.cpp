class Solution {
public:
    bool isPalindrome(string s) {
        string new_str = "";
        
        for(char c: s){
            if(isalnum(c)){
                new_str += tolower(c);
            }
        }

        int i = 0;
        int j = new_str.size()-1;
        while(i<j){
            if(new_str[i]!=new_str[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};