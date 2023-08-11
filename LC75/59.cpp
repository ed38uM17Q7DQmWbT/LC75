//3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> frqctr;
        int solution = 0;
        int hi = 0;
        int lo = 0;

        while (hi < s.size()) {
            frqctr[s[hi]]++;
            while (frqctr[s[hi]] > 1) {
                frqctr[s[lo]]--;
                lo++;
            }
            solution = max(solution, hi - lo + 1);
            hi++;
        }
        return solution;
    }
};