/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 20:45                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 9.9 MB                               
*  problem: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays
****************************************************************************************/
vector<int>a,b;
int n,dp[14+2][(1<<14)+2];
int dfs(int j,int msk)
{
  if(msk+1==(1<<n))return 0;
  if(dp[j][msk]!=-1)return dp[j][msk];
  int ret=2000000000;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    ret=min(ret,(b[i]^a[j])+dfs(j+1,msk|(1<<i)));
  }
  return dp[j][msk]=ret;
}
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
      a=nums1,b=nums2;
      n=a.size();
      memset(dp,-1,sizeof dp);
      return dfs(0,0);
    }
};