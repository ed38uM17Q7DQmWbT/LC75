//54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> solution;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rgtbnd = cols - 1;
        int btmbnd = rows - 1;
        int lftbnd = 0;
        int topbnd = 0;

        while (true) {
            for (int xpos = lftbnd; xpos <= rgtbnd; xpos++) {
                solution.push_back(matrix[topbnd][xpos]);
            }
            topbnd++;
            if (solution.size() == rows * cols)
                break;
            for (int ypos = topbnd; ypos <= btmbnd; ypos++) {
                solution.push_back(matrix[ypos][rgtbnd]);
            }
            rgtbnd--;
            if (solution.size() == rows * cols)
                break;
            for (int xpos = rgtbnd; xpos >= lftbnd; xpos--) {
                solution.push_back(matrix[btmbnd][xpos]);
            }
            btmbnd--;
            if (solution.size() == rows * cols)
                break;
            for (int ypos = btmbnd; ypos >= topbnd; ypos--) {
                solution.push_back(matrix[ypos][lftbnd]);
            }
            lftbnd++;
            if (solution.size() == rows * cols)
                break;
        }
        return solution;
    }
};