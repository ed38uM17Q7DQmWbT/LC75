//56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> solution;

        for (int i = 0; i < intervals.size(); i++) {
            if (solution.empty() || solution.back()[1] < intervals[i][0]) {
                solution.push_back(intervals[i]);
            }
            else {
                solution.back()[1] = max(solution.back()[1], intervals[i][1]);
            }

        }
        return solution;
    }
};