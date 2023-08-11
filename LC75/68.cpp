//57. Insert Interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> solution;
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) {
            solution.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval = { min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1]) };
            i++;
        }
        solution.push_back(newInterval);
        while (i < n) {
            solution.push_back(intervals[i]);
            i++;
        }
        return solution;
    }
};