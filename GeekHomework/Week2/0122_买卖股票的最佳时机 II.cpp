
//122. 买卖股票的最佳时机 II

//解法一：贪心
//贪心策略：后1天比当前股价高--买入；后1天比当前股价低--卖出
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, tmp;
        for (int i = 1; i < prices.size(); ++i) {
            tmp = prices[i] - prices[i-1];
            if(tmp > 0){
                profit += tmp;
            }
        }
        return profit;
    }
};

