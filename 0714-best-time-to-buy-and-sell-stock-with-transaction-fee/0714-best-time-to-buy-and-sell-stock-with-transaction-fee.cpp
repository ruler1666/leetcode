class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash=0;
        int hold= -prices[0];

        for(int i=1;i<prices.size();i++){
            hold =max(hold , cash-prices[i]);
            cash= max(cash , hold+prices[i]-fee);
        }
        return cash;
    }
};