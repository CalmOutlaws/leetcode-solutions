class Solution {
    int solve(int i, int j, string &word1, string &word2, int &n1, int &n2, vector<vector<int>> &dp)
    {
        if (i == n1 and j == n2)
        {
            return 0;
        }
        if (i == n1)
        {
            return (n2 - j);
        }
        if (j == n2)
        {
            return (n1 - i);
        }
        if (dp[i][j] != (-1))
        {
            return dp[i][j];
        }
        if (word1[i] == word2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, n1, n2, dp);
        }
        else
        {
            int inst = solve(i, j + 1, word1, word2, n1, n2, dp);
            int del = solve(i + 1, j, word1, word2, n1, n2, dp);
            int rpl = solve(i + 1, j + 1, word1, word2, n1, n2, dp);
            return dp[i][j] = min (inst, min (del, rpl)) + 1;
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(0, 0, word1, word2, n1, n2, dp);
    }
};