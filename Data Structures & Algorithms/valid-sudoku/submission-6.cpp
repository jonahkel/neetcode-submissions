class Solution {
public:

    int box_idx(int i, int j) {
        return (i/3)*3 + j/3;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row_bits(9);
        vector<int> col_bits(9);
        vector<int> box_bits(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int c_bit = 1 << (c - '0');
                if (row_bits[i] & c_bit){
                    return false;
                }
                if (col_bits[j] & c_bit){
                    return false;
                }
                if (box_bits[box_idx(i,j)] & c_bit){
                    return false;
                }
                row_bits[i] |= c_bit;
                col_bits[j] |= c_bit;
                box_bits[box_idx(i,j)] |= c_bit;
            }
        }
        return true;
    }
};
