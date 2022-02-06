/****************************************************************************************
*  @author: kzvd4729                                         created: 06/02/2021 22:03                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 6.4 MB                               
*  problem: https://leetcode.com/problems/interleaving-string
****************************************************************************************/
string a,b,c;
int dp[2][100+2][2][2];
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
          if(k==(int)c.size())dp[k%2][j][f][tr]=1;
          else
          {
            dp[k%2][j][tr][f]=0;
            if(f)dp[k%2][j][tr][f]|=dp[k%2][j][tr^1][0];
            int i=k-j;
            if(tr==0 && i<(int)a.size() && a[i]==c[k])dp[k%2][j][tr][f]|=dp[(k+1)%2][j][tr][1];
            if(tr==1 && j<(int)b.size() && b[j]==c[k])dp[k%2][j][tr][f]|=dp[(k+1)%2][j+1][tr][1];
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
        if((int)b.size()>(int)a.size())swap(a,b);
        if((int)a.size()+(int)b.size()!=(int)c.size())return false;
        //memset(dp,0,sizeof dp);
                        return dfs();
            }
};