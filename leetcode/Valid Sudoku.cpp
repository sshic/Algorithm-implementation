#60 mili secs for large data set

class Solution {
public:
   bool isValid(vector<vector<char> > &board, int x, int y)  {  
        int i, j;  
        for (i = 0; i < 9; i++)  
            if (i != x && board[i][y] == board[x][y])  
                return false;  
        for (j = 0; j < 9; j++)  
            if (j != y && board[x][j] == board[x][y])  
                return false;  
        for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)  
            for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)  
                if (i != x && j != y && board[i][j] == board[x][y])  
                    return false;  
        return true;  
    }  
    bool isValidSudoku(vector<vector<char> > &board)  
    {  
        for (int i = 0; i < 9; ++i)  
            for (int j = 0; j < 9; ++j){  
                if ('.' != board[i][j]) 
                    if (!isValid(board, i, j))  
                        return false;    
            }  
        return true;  
    }
};