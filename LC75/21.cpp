//746. Min Cost Climbing Stairs
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = cost.size() - 2; i > 0; i--)
            cost[i - 1] += min(cost[i], cost[i + 1]);
        return min(cost[0], cost[1]);
    }
};