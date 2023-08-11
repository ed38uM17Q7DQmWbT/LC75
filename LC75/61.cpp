//76. Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> frqctr(128, 0);
        for (int i = 0; i < t.length(); i++) {
            frqctr[t[i]]++;
        }
        int pairsrqd = t.length();
        int pairsmet = 0;
        int solutionindx = 0;
        int solutionsize = INT_MAX;

        int hi = 0;
        int lo = 0;
        while (hi < s.length()) {
            if (frqctr[s[hi]] > 0) {
                pairsmet++;
            }
            frqctr[s[hi]]--;
            while (lo <= hi && pairsmet == pairsrqd) {
                if (solutionsize >= hi - lo + 1) {
                    solutionindx = lo;
                    solutionsize = hi - lo + 1;
                }
                frqctr[s[lo]]++;
                if (frqctr[s[lo]] > 0) {
                    pairsmet--;
                }
                lo++;
            }
            hi++;
        }
        return (solutionsize == INT_MAX) ? "" : s.substr(solutionindx, solutionsize);
    }
};