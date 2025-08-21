class Solution {
public:
    int countPalindrome(string &s, int left, int right){
        int count = 0;

        while(left>=0 && right<s.size()){
            if(s[left] == s[right]){
                count++;
                left--;
                right++;
            }else{
                break;
            }
        }

        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i<s.size(); i++){
            ans += countPalindrome(s, i, i);    //odd palindromes
            ans += countPalindrome(s, i-1, i);  //even palindromes
        }

        return ans;
    }
};