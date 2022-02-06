/****************************************************************************************
*  @author: kzvd4729                                         created: 06/02/2021 21:39                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 6.7 MB                               
*  problem: https://leetcode.com/problems/interleaving-string
****************************************************************************************/
string a,b,c;
int dp[100+2][200+2][2][2];
bool dfs(int i,int j,int k,int tr,int f)
{
  if(k==(int)c.size())return true;
  if(dp[j][k][tr][f]!=-1)return dp[j][k][tr][f];
    bool ret=false;
  if(f)ret=dfs(i,j,k,tr^1,0);
  if(tr==0)
  {
    if(i<(int)a.size() && a[i]==c[k])ret|=dfs(i+1,j,k+1,tr,1);
  }
  else
  {
    if(j<(int)b.size() && b[j]==c[k])ret|=dfs(i,j+1,k+1,tr,1);
  }
  return dp[j][k][tr][f]=ret;
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
                a=s1,b=s2,c=s3;
        if((int)a.size()+(int)b.size()!=(int)c.size())return false;
        memset(dp,-1,sizeof dp);
                return (dfs(0,0,0,0,0)|dfs(0,0,0,1,0));
            }
};