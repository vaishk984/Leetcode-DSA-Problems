class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0){
            return false;
        }

        int openCount = 0, closeCount = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(' || locked[i] == '0'){
                openCount++;
            }else{
                openCount--;
            }

            if(openCount<0){
                return false;
            }
        }

        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ')' || locked[i] == '0'){
                closeCount++;
            }else{
                closeCount--;
            }

            if(closeCount<0) return false;
        }

        return true;
    }
};