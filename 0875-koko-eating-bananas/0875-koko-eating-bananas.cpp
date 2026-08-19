class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid)
    {
        long long int count = 0;

        for (auto it : piles)
        {
            if (mid > it)
            {
                count += 1;
            }
            else 
            {
                if (it % mid == 0)
                {
                    count += (it / mid);
                }
                else
                {
                    count += (it / mid) + 1;
                }
            }
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (auto it : piles)
        {
            maxi = max (maxi, it);
        }
        int low = 1, high = maxi;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};