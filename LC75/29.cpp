//1046. Last Stone Weight
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> dummy;
        for (int i = 0; i < stones.size(); i++) {
            dummy.push(stones[i]);
        }
        int x = 0;
        int y = 0;



        while (dummy.size() > 1) {
            x = dummy.top();
            dummy.pop();
            y = dummy.top();
            dummy.pop();


            if (x == y) {
                x = 0;
                y = 0;
                continue;
            }
            if (x > y) {
                dummy.push(x - y);
            }
        }
        return (dummy.size()) ? dummy.top() : 0;
    }
};