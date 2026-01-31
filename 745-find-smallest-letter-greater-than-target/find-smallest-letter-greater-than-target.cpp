class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char nextGreater = letters[0];
        for(int i = 0; i<letters.size(); i++){
            if(letters[i]>target){
                nextGreater = letters[i];
                break;
            } 
        }

        return nextGreater;
    }
};