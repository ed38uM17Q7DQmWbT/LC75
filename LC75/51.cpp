//994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({ i, j });
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        m--;
        n--;
        int ans = 0;
        while (!q.empty() && fresh > 0)
        {
            int sz = q.size();
            while (sz--)
            {
                vector<int> p = q.front();
                int r = p[0];
                int c = p[1];
                q.pop();
                if (r > 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push({ r - 1, c });
                    fresh--;
                }
                if (c < n && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push({ r, c + 1 });
                    fresh--;
                }
                if (r < m && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push({ r + 1, c });
                    fresh--;
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push({ r, c - 1 });
                    fresh--;
                }
            }
            ans++;
        }

        if (fresh > 0)   return -1;
        return ans;
    }
};