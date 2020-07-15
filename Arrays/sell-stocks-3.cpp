// Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if(n==0)
            return 0;

        vector<int> dp(n+1,0);
        int minn = prices[0];
        int profit = 0;

        for(int i = 1; i<n; i++)
        {
            dp[i] = max(profit, (prices[i] - minn));
            minn = min(minn, prices[i]);
            profit = max(profit, dp[i]);
        }

        int maxx1 = 0;

        for(int i = 1; i<n; i++)
        {
            maxx1 = max(dp[i], maxx1);
        }

        vector<int> dpleft(n+1,0);
        int maxx = prices[n-1];
        profit = 0;
        for(int i = n-1; i>=0; i--)
        {
            dpleft[i] = max(profit, (maxx - prices[i]));
            // cout << dpleft[i] << " ";
            maxx = max(maxx, prices[i]);                                         profit = max(profit, dpleft[i]);

        }

        int maxx2 = INT_MIN;

        for(int i = 0; i<n; i++)
        {
            maxx2 = max(maxx2, dp[i] + dpleft[i]);
        }

        // cout << dp[2] << " "<< dpleft[2];
        // cout << maxx1 << " " <<maxx2;
        return max(maxx2,maxx1);

    }
};
