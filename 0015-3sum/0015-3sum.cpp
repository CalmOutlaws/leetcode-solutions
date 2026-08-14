class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                }
                else if (sum > 0) k--;
                else j++;
            }
        }
        set <vector<int>> s (ans.begin(), ans.end());
        vector<vector<int>> ans2 (s.begin(), s.end());
        return ans2;
    }
};