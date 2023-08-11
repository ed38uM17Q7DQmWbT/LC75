//202. Happy Number
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> frqctr;


        while (true) {
            if (n == 1) {
                return true;
            }
            if (frqctr.count(n)) {
                return false;
            }
            frqctr.insert({ n, 1 });


            int dummy = 0;
            while (n) {
                dummy += (n % 10) * (n % 10);
                n /= 10;
            }
            n = dummy;
        }
    }
};