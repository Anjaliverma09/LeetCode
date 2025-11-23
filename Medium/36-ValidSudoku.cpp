class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char num = board[r][c];

                if(num != '.'){
                    string row = string(1, num) + " row " + to_string(r);
                    string col = string(1, num) + " col " + to_string(c);
                    string box = string(1, num) + " box " + to_string(r/3) + to_string(c/3);

                    if(!seen.insert(row).second ||
                       !seen.insert(col).second || 
                       !seen.insert(box).second)
                        return false;
                }
            }
        }
        return true;
    }
};