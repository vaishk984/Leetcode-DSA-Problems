class Solution {
    public boolean isPalindrome(String s) {
        int start = 0;
        int end = s.length()-1;

        while(start<=end){
            if(!Character.isLetterOrDigit(s.charAt(start))){
                start++;
            }

            else if(!Character.isLetterOrDigit(s.charAt(end))){
                end--;
            }

            else if(Character.toLowerCase(s.charAt(start)) != Character.toLowerCase(s.charAt(end))){
                return false;
            }
            else{
                start++;
                end--;
            }
        }

        return true;
    }

    public static boolean palindrome(int i, String s){
        
        if(i>=s.length()/2){
            return true;
        }

        if(s.charAt(i)!=s.charAt(s.length()-1-i)){
            return false;
        }

        return palindrome(i+1, s);
    }
}