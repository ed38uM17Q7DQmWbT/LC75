//692. Top K Frequent Words
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frqctr;
        for (auto& i : words) {
            frqctr[i]++;
        }


        vector<pair<int, string>> dummy;
        for (auto& i : frqctr) {
            dummy.push_back({ -i.second, i.first });
        }
        sort(dummy.begin(), dummy.end());


        vector<string> solution;
        for (int i = 0; i < k; i++) {
            solution.push_back(dummy[i].second);
        }
        return solution;
    }
};