class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, minAddsRequired = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
                open++;
            }else {
                if(open>0){
                    open--;
                }else{
                    minAddsRequired++;
                }
            }
        }

        return open + minAddsRequired;
    }
};