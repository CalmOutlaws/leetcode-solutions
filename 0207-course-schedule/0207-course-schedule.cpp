class Solution {
public:
    int count = 0;
    void helper (int i, vector<int> &dp, vector<vector<int>> &C)
    {
        int m = C[i].size();
        for (int j = 0; j < m; j++)
        {
            if (dp[C[i][j]] == 0)
                return;
        }

        dp[i] = 1;
        count++;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> C(numCourses);
        int m = prerequisites.size();
        vector<int>dp(numCourses);
        for (int i = 0; i < m; i++)
        {
            C[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }    
        for (int i = 0; i < numCourses; i++)
        {
            if (C[i].size() == 0)
            {
                count++;
                dp[i] = 1;
            }
        }

        while (count != numCourses)
        {
            int cur = count;
            for (int i = 0; i < numCourses; i++)
            {
                if (dp[i] == 0)
                {
                    helper (i, dp, C);
                }
            }

            if (cur == count)
                return false;
        }

        return true;
    }
};