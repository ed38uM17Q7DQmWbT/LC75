//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyin = prices[0];
        int profit = 0;


        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buyin)
                buyin = prices[i];
            if (prices[i] - buyin > profit)
                profit = prices[i] - buyin;
        }
        return profit;
    }
};