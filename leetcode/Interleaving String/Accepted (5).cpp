/****************************************************************************************
*  @author: kzvd4729                                         created: 06/02/2021 21:56                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 6.7 MB                               
*  problem: https://leetcode.com/problems/interleaving-string
****************************************************************************************/
string a,b,c;
int dp[200+2][100+2][2][2];
bool dfs()
{
  for(int k=(int)c.size();k>=0;k--)
  {
    for(int j=min((int)b.size(),k);j>=0;j--)
    {
      for(int f=0;f<=1;f++)
      {
        for(int tr=0;tr<=1;tr++)
        {
          if(k==(int)c.size())dp[k][j][f][tr]=1;
          else
          {
            if(f)dp[k][j][tr][f]|=dp[k][j][tr^1][0];
            int i=k-j;
            if(tr==0 && i<(int)a.size() && a[i]==c[k])dp[k][j][tr][f]|=dp[k+1][j][tr][1];
            if(tr==1 && j<(int)b.size() && b[j]==c[k])dp[k][j][tr][f]|=dp[k+1][j+1][tr][1];
          }
        }
      }
    }
  }
  return (dp[0][0][0][0]|dp[0][0][1][0]);
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
                a=s1,b=s2,c=s3;
        if((int)a.size()+(int)b.size()!=(int)c.size())return false;
        memset(dp,0,sizeof dp);
                return dfs();
            }
};