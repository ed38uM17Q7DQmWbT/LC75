//200. Number of Islands
class Solution {
public:
    void helper(vector<vector<char>>& grid, int r, int n, int c, int m) {
        grid[r][c] = '0';
        if (r > 0 && grid[r - 1][c] == '1') {
            helper(grid, r - 1, n, c, m);
        }
        if (c < m && grid[r][c + 1] == '1') {
            helper(grid, r, n, c + 1, m);
        }
        if (r < n && grid[r + 1][c] == '1') {
            helper(grid, r + 1, n, c, m);
        }
        if (c > 0 && grid[r][c - 1] == '1') {
            helper(grid, r, n, c - 1, m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int solution = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    solution++;
                    helper(grid, r, grid.size() - 1, c, grid[0].size() - 1);
                }
            }
        }
        return solution;
    }
};