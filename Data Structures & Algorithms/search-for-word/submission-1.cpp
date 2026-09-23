class Solution {
public:
    
    bool helper(vector<vector<char>>& board, string word, int word_idx, int x, int y){
        if (x < 0 || x >= board.size() 
        || y < 0 || y >= board[0].size()) return false;
        if (board[x][y] != word[word_idx]) return false;
        ++word_idx;
        if (word_idx == word.size()) return true;
        char temp = board[x][y];
        board[x][y] = '-';
        bool result = (helper(board, word, word_idx, x-1, y)
        || helper(board, word, word_idx, x+1, y)
        || helper(board, word, word_idx, x, y-1)
        || helper(board, word, word_idx, x, y+1));
        board[x][y] = temp;
        return result;

    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
