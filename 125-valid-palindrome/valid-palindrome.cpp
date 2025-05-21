class Solution {
public:
    bool isPalindrome(string s) {
        string new_str = "";
        
        for(char c: s){ 
            if (isalnum(c)) {
                new_str += tolower(c);
            }
        }

        int n = new_str.size();
        int i = 0;
        int j = n-1;
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