class Solution {
    public static boolean isValid(String word){
        if(word.isEmpty()){
            return false;
        }

        char start = word.charAt(0);
        char end = word.charAt(word.length()-1);

        return isVowel(start) && isVowel(end);
    }

    public static boolean isVowel(char c){
        return "aeiou".indexOf(c) != -1;
    }
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int prefix[] = new int[n];

        prefix[0] = isValid(words[0]) ? 1:0;
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + (isValid(words[i])?1:0);
        }

        int result[] = new int[queries.length];
        for(int i = 0; i<queries.length; i++){
            int li = queries[i][0];
            int ri = queries[i][1];

            result[i] = prefix[ri] - (li>0 ? prefix[li-1]:0);
        }
        return result;
    }

}