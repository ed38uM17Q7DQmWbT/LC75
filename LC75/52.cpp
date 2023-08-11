//417. Pacific Atlantic Water Flow
class Solution {
public:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& v)
    {
        int x[5] = { 0, 1, 0, -1, 0 };
        int m = heights.size();
        int n = heights[0].size();
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            v[i][j] = true;
            for (int k = 0; k < 4; k++)
            {
                int r = i + x[k];
                int c = j + x[k + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && heights[r][c] >= heights[i][j] && v[r][c] == false)
                {
                    q.push({ r, c });
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        queue<pair<int, int>> q1, q2;
        for (int j = 0; j < n; j++)
        {
            q1.push({ 0, j });
            q2.push({ m - 1, j });
        }
        for (int i = 0; i < m; i++)
        {
            q1.push({ i, 0 });
            q2.push({ i, n - 1 });
        }
        bfs(heights, q1, p);
        bfs(heights, q2, a);
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (p[i][j] && a[i][j])
                    ans.push_back({ i, j });
        }
        return ans;
    }
};