//547. Number of Provinces
class Solution {
public:
    void helper(vector<vector<int>>& isConnected, vector<int>& dummy, int i, int n)
    {
        dummy[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i && dummy[j] == 0 && isConnected[j][i] == 1)
                helper(isConnected, dummy, j, n);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> dummy(n, 0);
        int solution = 0;
        for (int i = 0; i < n; i++)
        {
            if (dummy[i] == 0)
            {
                solution++;
                helper(isConnected, dummy, i, n);
            }
        }
        return solution;
    }
};