/**
Djikstra's inspired algorithm:

Keep priority queue of cells to visit, sorted by max effort to reach it.

Start at top-left spot, put adjacent cells into pq along with effort.

Repeatedly go through pq
    If I'm at the bottom-right, I'm done! return effort.

foreach adjacent:
    Find the effort it would take to get there. 
    If it's less than what's currently stored, then put the effort+cell into PQ


    

**/

struct Cell {
    int row;
    int col;
    int effort;
};

struct CellCompare {
    bool operator()(const Cell& c1, const Cell& c2) const {
        return c1.effort > c2.effort;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> min_effort(rows, vector<int>(cols, INT_MAX));
        priority_queue<Cell, vector<Cell>, CellCompare> pq;
        pq.push({0,0,0});
        min_effort[0][0] = 0;
        while (!pq.empty()) {
            Cell c = pq.top();
            pq.pop();
            if (c.row == rows - 1 && c.col == cols - 1) {
                return c.effort;
            }
            int c_height = heights[c.row][c.col];
            if (c.row > 0) {
                int up_height = heights[c.row-1][c.col];
                int up_effort = max(abs(up_height - c_height), c.effort);
                if (up_effort < min_effort[c.row-1][c.col]) {
                    min_effort[c.row-1][c.col] = up_effort;
                    pq.push({c.row-1, c.col, up_effort});
                }
            }
            if (c.col > 0) {
                int left_height = heights[c.row][c.col-1];
                int left_effort = max(abs(left_height - c_height), c.effort);
                if (left_effort < min_effort[c.row][c.col-1]) {
                    min_effort[c.row][c.col-1] = left_effort;
                    pq.push({c.row, c.col-1, left_effort});
                }
            }
            if (c.row < rows - 1) {
                int down_height = heights[c.row+1][c.col];
                int down_effort = max(abs(down_height - c_height), c.effort);
                if (down_effort < min_effort[c.row+1][c.col]) {
                    min_effort[c.row+1][c.col] = down_effort;
                    pq.push({c.row+1, c.col, down_effort});
                }
            }
            if (c.col < cols - 1) {
                int right_height = heights[c.row][c.col+1];
                int right_effort = max(abs(right_height - c_height), c.effort);
                if (right_effort < min_effort[c.row][c.col+1]) {
                    min_effort[c.row][c.col+1] = right_effort;
                    pq.push({c.row, c.col+1, right_effort});
                }
            }
        }
        return min_effort.back().back();
    }
};