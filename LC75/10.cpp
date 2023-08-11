//409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        int pair_ctr = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i + 1]) {
                pair_ctr++;
                i++;
            }
        }
        if (s.size() > 2 * pair_ctr)
            return 2 * pair_ctr + 1;
        if (s.size() == 2 * pair_ctr)
            return 2 * pair_ctr;
        return -1;
    }
};