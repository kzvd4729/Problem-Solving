/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-10 18:15:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 100                                        memory_used (MB): 2.8                             
*  problem: https://vjudge.net/problem/LightOJ-1315
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,tc,n,dp[502][502];
int dx[]={+1,-1,-1,-2,-3,-2};
int dy[]={-2,-3,-2,-1,-1,+1};
int grundy(int x,int y)
{
  if(dp[x][y]!=-1)return dp[x][y];
  set<int>st;
  for(int i=0;i<6;i++)
  {
    int xx=x+dx[i];
    int yy=y+dy[i];
    if(xx>=0&&yy>=0)
      st.insert(grundy(xx,yy));
  }
  for(int i=0;i<N;i++)
    if(st.find(i)==st.end())return dp[x][y]=i;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp,-1,sizeof(dp));

  cin>>t;
  while(t--)
  {
    cin>>n;int xxr=0;
    for(int i=1;i<=n;i++)
    {
      int x,y;cin>>x>>y;
      xxr^=grundy(x,y);
    }
    if(xxr)cout<<"Case "<<++tc<<": Alice"<<"\n";
    else cout<<"Case "<<++tc<<": Bob"<<"\n";
  }
  return 0;
}