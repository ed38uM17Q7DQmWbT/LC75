//424. Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) {
            return 0;
        }


        int hi = 0;
        int lo = 0;
        int frqcap = 0;
        vector<int> frqctr(26, 0);
        while (hi < s.size()) {
            frqctr[s[hi] - 'A']++;
            frqcap = max(frqcap, frqctr[s[hi] - 'A']);
            if (hi - lo + 1 - frqcap > k) {
                frqctr[s[lo] - 'A']--;
                lo++;
            }
            hi++;
        }
        return s.size() - lo;
    }
};