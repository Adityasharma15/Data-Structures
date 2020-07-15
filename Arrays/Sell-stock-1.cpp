// Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n==0)
            return 0;

        vector<int> dp(n+1,0);
        int minn = prices[0];

        for(int i = 1; i<n; i++)
        {
            dp[i] = (prices[i] - minn);
            minn = min(minn, prices[i]);
        }

        int maxx = 0;

        for(int i = 1; i<n; i++)
        {
            maxx = max(dp[i], maxx);
        }

        return maxx;
    }
};
