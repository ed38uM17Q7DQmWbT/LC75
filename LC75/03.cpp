//205. Isomorphic Strings
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> slog;
        int sctr = 0;
        unordered_map<char, int> tlog;
        int tctr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!slog.count(s[i])) {
                slog.insert({ s[i], sctr });
                sctr++;
            }
            if (!tlog.count(t[i])) {
                tlog.insert({ t[i], tctr });
                tctr++;
            }
            if (slog.at(s[i]) != tlog.at(t[i]))
                return false;
        }
        return true;
    }
};