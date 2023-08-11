//392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;
        if (t.empty())
            return false;


        int sctr = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[sctr])
                sctr++;
            if (sctr == s.size())
                return true;
        }
        return false;
    }
};