class Solution {
public:
    int totalCapacity(vector<int> weights, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
        }
        return sum;
    }

    int checkCapacity(vector<int> &weights, int capacity)
    {
        int n = weights.size();
        int curr_capacity = 0;
        int days = 1;
        for (int i = 0; i < n; i++)
        {
            curr_capacity += weights[i];
            if (curr_capacity > capacity)
            {
                days++;
                curr_capacity = weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = *max_element(weights.begin(), weights.end());
        int total = totalCapacity(weights, n);
        int low = maxi;
        int high = total;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checkCapacity(weights, mid) <= days)
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;    
    }
};