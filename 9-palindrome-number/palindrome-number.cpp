class Solution {
public:
    bool isPalindrome(int x) {
        long long digit = x;
        long long rev = 0;

        if(x<0){
            return false;
        }

        while(digit!=0){
            rev = rev*10LL + digit%10LL;
            digit = digit/10;
        }

        return x==rev;
    }
};