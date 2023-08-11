//438. Find All Anagrams in a String
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};


        vector<int> solution;
        vector<int> counting_arrayP(26, 0);
        vector<int> counting_arrayS(26, 0);
        int windowlo = 0;
        int windowhi = 0;


        while (windowhi < p.size()) {
            counting_arrayS[s[windowhi] - 'a']++;
            counting_arrayP[p[windowhi] - 'a']++;
            windowhi++;
        }


        while (true) {
            if (counting_arrayS == counting_arrayP)
                solution.push_back(windowlo);
            if (windowhi == s.size())
                break;
            counting_arrayS[s[windowlo] - 'a']--;
            windowlo++;
            counting_arrayS[s[windowhi] - 'a']++;
            windowhi++;
        }
        return solution;
    }
};