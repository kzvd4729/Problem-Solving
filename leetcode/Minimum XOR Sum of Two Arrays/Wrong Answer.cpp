/****************************************************************************************
*  @author: kzvd4729                                         created: 05/30/2021 00:11                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays
****************************************************************************************/
int dp[21][(1 << 21)];
class Solution
{
public:
    int solve(int i, int mask, int &n, vector<int> &a, vector<int> &b)
    {
        if (i == n)
            return 0;
        if (dp[i][mask] != -1)
            return dp[i][mask];
        int answer = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
                answer = min(answer, a[i] ^ b[j] + solve(i + 1, (mask ^ (1 << j)), n, a, b));
        }
        return dp[i][mask] = answer;
    }
    int minimumXORSum(vector<int> &a, vector<int> &b)
    {
        memset(dp, -1, sizeof dp);
        int n = a.size();
        return solve(0, (1 << n) - 1, n, a, b);
    }
};