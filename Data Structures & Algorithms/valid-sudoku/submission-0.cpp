class Solution {
    bool isValid(vector<vector<char>>& board, int i, int j){
        char ch = board[i][j];

        for(int k = 0; k < 9; k++){
            int box_i = (i/3)*3 + k/3;
            int box_j = (j/3)*3 + k%3;

            
            if((k != j and board[i][k] == ch) or
            (k != i and board[k][j] == ch)
            or ((not (box_i == i and box_j == j)) and board[box_i][box_j] == ch))
                return false;

        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.'){
                    if(not isValid(board, i, j))
                        return false;
                }
        
        return true;
    }
};
