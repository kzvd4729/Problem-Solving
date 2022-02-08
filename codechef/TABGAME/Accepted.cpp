/****************************************************************************************
*  @author: kzvd4729                                         created: 07-09-2018 18:28:56                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.70 sec                                        memory_used: 23.2M                                
*  problem: https://www.codechef.com/SEPT18A/problems/TABGAME
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int dp1[N+2][6],dp2[6][N+2];
string n,m;
int dfs1(int i,int j)
{
  if(dp1[i][j]!=-1)return dp1[i][j];
  int b=dfs1(i-1,j)&dfs1(i,j-1);
  return dp1[i][j]=!b;
}
int dfs2(int i,int j)
{
  if(dp2[i][j]!=-1)return dp2[i][j];
  int b=dfs2(i-1,j)&dfs2(i,j-1);
  return dp2[i][j]=!b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>m>>n;
    while(m.size()<=4)m.push_back('0');
    while(n.size()<=4)n.push_back('0');
    for(int i=n.size();i>=0;i--)
      for(int j=0;j<=4;j++)
        dp1[i][j]=-1;
    for(int i=4;i>=0;i--)
      for(int j=m.size();j>=0;j--)
        dp2[i][j]=-1;
    memset(dp2,-1,sizeof(dp2));
    for(int i=1;i<=n.size();i++)
    {
      dp1[i][0]=n[i-1]-'0';
      if(i<=4)dp2[i][0]=n[i-1]-'0';
    }
    for(int i=1;i<=m.size();i++)
    {
      dp2[0][i]=m[i-1]-'0';
      if(i<=4)dp1[0][i]=m[i-1]-'0';
    }
    dfs1(n.size(),4);dfs2(4,m.size());
    int q;cin>>q;string ans;
    while(q--)
    {
      int u,v;cin>>u>>v;
      int mn=min(u,v);
      if(mn>4)u-=(mn-4),v-=(mn-4);
      if(v<=4)ans.push_back(dp1[u][v]+'0');
      else ans.push_back(dp2[u][v]+'0');
    }
    cout<<ans<<endl;
  }
  return 0;
}