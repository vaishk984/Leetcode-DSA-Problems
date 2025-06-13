class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char curr = board[i][j];
                if (curr == '.') continue;

                // Check row
                if (rows[i].count(curr)) return false;
                rows[i].insert(curr);

                // Check column
                if (cols[j].count(curr)) return false;
                cols[j].insert(curr);

                // Check 3x3 box
                int boxIdx = (i / 3) * 3 + (j / 3);
                if (boxes[boxIdx].count(curr)) return false;
                boxes[boxIdx].insert(curr);
            }
        }

        return true;
    }
};