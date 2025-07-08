class Solution {
public:
    int reverse(int x) {
        int digit;
        int answer = 0;
        while(x!=0){
            digit = x%10;
            if((answer>INT_MAX/10) || (answer<INT_MIN/10)){
                return 0;
            }
            x = x/10;
            answer = answer *10 + digit;
        }
        return answer;
    }
};