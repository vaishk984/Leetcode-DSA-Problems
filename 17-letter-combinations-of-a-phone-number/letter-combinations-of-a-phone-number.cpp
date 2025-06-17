class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> phoneMap = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string path = "";
        vector<string> result;

        getCombinations(digits, 0, path, result, phoneMap);

        return result;
    }

    void getCombinations(string digits, int index,string &path, vector<string> &result, vector<string> &phoneMap){
        if(index==digits.size()){
            result.push_back(path);
            return;
        }

        string possibleLetters = phoneMap[digits[index] - '0'];

        for(char c: possibleLetters){
            path.push_back(c);
            getCombinations(digits, index+1, path, result, phoneMap);
            path.pop_back();
        }
    }   
};