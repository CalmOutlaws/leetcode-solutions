class Solution {
public:
    bool solve(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 0; t <= target; t++)
            {
                bool incl = 0;
                if (t - nums[index] >= 0)
                {
                    incl = dp[index + 1][t - nums[index]];
                }
                bool excl = dp[index + 1][t];
                dp[index][t] = incl or excl;
            }
        }
        return dp[0][target];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        if (total & 1) return false;
        int target = total / 2;
        return solve(nums, target);
    }
};