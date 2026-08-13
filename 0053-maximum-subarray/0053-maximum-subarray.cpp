class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int csum = 0, maxsum = INT_MIN;
        int n = nums.size() - 1;
        for (int i = 0; i <= n; i++)
        {
            csum += nums[i];
            maxsum = max(maxsum, csum);
            if (csum < 0)
            {
                csum = 0;
            }
        }
        return maxsum;
    }
};