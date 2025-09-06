class Solution {
public:
    bool checkValidString(string s) {
        int high = 0, low = 0;
        for(char c: s){
            if(c=='('){
                high++;
                low++;
            }else if(c==')'){
                low--;
                high--;
            }else{
                low--;
                high++;
            }

            if(low<0){
                low = 0;
            }

            if(high<0){
                return false;
            }
        }

        return !low;
    }
};