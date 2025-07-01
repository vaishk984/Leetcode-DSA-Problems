class Solution {
public:
    int maxScore(string s) {
        int countZeroes = 0;
        int countOnes = 0;
        int score;
        int maxScore = INT_MIN;

        for(int i = 0; i<s.size(); i++){
            if(s[i]=='1'){
                countOnes++;
            }
        }

        for(int i = 0; i<s.size()-1; i++){
            if(s[i]=='0'){
                countZeroes++;
            }else{
                countOnes--;
            }
            score = countZeroes + countOnes;

            maxScore = max(score, maxScore);

        }

        return maxScore;
    }
};