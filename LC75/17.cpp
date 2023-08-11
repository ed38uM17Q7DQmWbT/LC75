//733. Flood Fill


class Solution {
public:
    void helper(vector<vector<int>>& image, int r, int n, int c, int m, int flood, int fill) {
        image[r][c] = fill;
        if (r > 0 && image[r - 1][c] == flood) {
            helper(image, r - 1, n, c, m, flood, fill);
        }
        if (c < m && image[r][c + 1] == flood) {
            helper(image, r, n, c + 1, m, flood, fill);
        }
        if (r < n && image[r + 1][c] == flood) {
            helper(image, r + 1, n, c, m, flood, fill);
        }
        if (c > 0 && image[r][c - 1] == flood) {
            helper(image, r, n, c - 1, m, flood, fill);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int fill) {
        int m = image[0].size() - 1;
        int n = image.size() - 1;
        if (fill != image[r][c]) {
            helper(image, r, n, c, m, image[r][c], fill);
        }
        return image;
    }
};