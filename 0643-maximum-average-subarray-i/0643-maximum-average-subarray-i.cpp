class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum = 0;
        double maxavg = 0;
        for(int i=0; i<k; i++) {
            windowSum += nums[i];
        }
        maxavg = windowSum/k;
        for(int i=k; i<nums.size(); i++) {
            windowSum -= nums[i-k];
            windowSum += nums[i];
            maxavg = max(maxavg, windowSum / k);
        }
        return maxavg;
    }
};