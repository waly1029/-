class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        // 计算连续2天的利润差值
        // 如果为正数则加入
        // 否则继续
        for(int i=1; i<prices.size(); ++i) {
            if(prices[i]-prices[i-1] > 0)
                result += prices[i]-prices[i-1];
        }

        return result;
    }
};
