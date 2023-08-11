//322. Coin Change
class Solution {
public:
    int helper(vector<int>& coins, vector<int>& memo, int subproblem) {
        if (subproblem < 0) {
            return -1;
        }
        if (memo[subproblem] != INT_MAX) {
            return memo[subproblem];
        }

        int min = INT_MAX;
        for (int coin : coins) {
            int result = helper(coins, memo, subproblem - coin) + 1;
            if (result > 0 && result < min) {
                min = result;
            }
        }
        memo[subproblem] = (min == INT_MAX) ? -1 : min;
        return memo[subproblem];
    }

    int coinChange(vector<int>& coins, int target) {
        vector<int> memo(target + 1, INT_MAX);
        memo[0] = 0;
        return helper(coins, memo, target);
    }
};