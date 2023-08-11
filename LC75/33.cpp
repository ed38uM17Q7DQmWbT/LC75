//1706. Where Will the Ball Fall
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> solution;
        int col = -1;
        int row = -1;
        for (int i = 0; i < grid[0].size(); i++) {
            col = i;
            row = 0;
            while (true) {
                int tile_look = grid[row][col];
                if (
                    col + tile_look < 0 ||
                    col + tile_look > grid[0].size() - 1 ||
                    tile_look != grid[row][col + tile_look]
                    ) {
                    solution.push_back(-1);
                    break;
                }
                if (row == grid.size() - 1) {
                    solution.push_back(col + grid[row][col]);
                    break;
                }
                col += grid[row][col];
                row++;

            }
        }
        return solution;
    }
};