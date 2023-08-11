//210. Course Schedule II
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> temp;
        vector<int> visitlist(numCourses, 0);
        //0 ~ unvisited
        //1 ~ in stack
        //2 ~ completed
        vector<vector<int>> adjacencies(numCourses);
        for (vector<int>& item : prerequisites) {
            adjacencies[item[1]].push_back(item[0]);
        }
        bool failure = false;
        function<void(int)> helper = [&](int cur) {
            visitlist[cur] = 1;
            if (!adjacencies[cur].empty()) {
                for (int& item : adjacencies[cur]) {
                    if (visitlist[item] == 1) {
                        failure = true;
                    }
                    if (visitlist[item] == 0) {
                        helper(item);
                    }
                }
            }
            visitlist[cur] = 2;
            temp.push(cur);
        };
        for (int i = 0; i < numCourses; i++) {
            if (visitlist[i] == 0) {
                helper(i);
            }
        }
        vector<int> solution;
        while (!temp.empty()) {
            solution.push_back(temp.top());
            temp.pop();
        }
        if (failure) {
            return {};
        }
        else {
            return solution;
        }
    }
};