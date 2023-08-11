//621. Task Scheduler
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frqctr(26, 0);
        for (auto i : tasks) {
            frqctr[i - 'A']++;
        }


        int fmax = 0;
        for (auto i : frqctr) {
            fmax = (i > fmax) ? i : fmax;
        }


        int nmax = 0;
        for (auto i : frqctr) {
            nmax += (i == fmax) ? 1 : 0;
        }

        return (tasks.size() > (fmax - 1) * (n + 1) + nmax) ? tasks.size() : (fmax - 1) * (n + 1) + nmax;
    }
};