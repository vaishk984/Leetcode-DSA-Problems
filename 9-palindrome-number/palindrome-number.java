class Solution {
    public boolean isPalindrome(int x) {
        int temp = x;
        int revNum = 0;
        while(x > 0){
            int lastDigit = x % 10;
            revNum = revNum * 10 + lastDigit;
            x = x/10;
        }

        return temp==revNum;
    }
}