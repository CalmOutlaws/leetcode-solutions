class Solution {
public:
    int robtrial(const vector<int>& nums)
    {
        int left = nums[0], mid = nums[1], right = nums[2] + nums[0];

        for (int i = 3; i < nums.size(); i++)
        {
            int tmp = right;
            right = max(left, mid) + nums[i];
            left = mid, mid = tmp;
        }
        return max(mid, right - nums[0]);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        int chanceA = robtrial(nums);
        rotate(nums.begin(), nums.begin() + nums.size() - 1, nums.end());
        int chanceB = robtrial(nums);
        rotate(nums.begin(), nums.begin() + 2, nums.end());
        int chanceC = robtrial(nums);
        int finalAns = max(chanceA, chanceB);
        return max(finalAns, chanceC);    
    }
};