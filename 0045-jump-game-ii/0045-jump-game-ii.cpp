class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j <= min(nums[i] + i, n - 1); j++)
            {
                dp[i] = min(dp[j] + 1, dp[i]);
            }
        }
        return dp[0];
    }
};