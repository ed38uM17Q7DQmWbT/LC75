//509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        vector<int> memo;
        memo.push_back(0);
        memo.push_back(1);


        for (int i = 2; i <= n; i++)
            memo.push_back(memo[i - 1] + memo[i - 2]);
        return memo[n];
    }
};