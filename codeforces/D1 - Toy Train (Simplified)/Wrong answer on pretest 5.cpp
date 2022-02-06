/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 23:02                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1130/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
vector<int>des[N+2];
int n;
struct data
{
  int lap,ex;
}aa[N+2];
int dis(int i,int j)
{
  if(j>i)return j-i;
  return j-i+n;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    des[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
  {
    if(des[i].size()==0)
    {
      aa[i]={0,0};continue;
    }
    int mn=1e9;
    for(auto x:des[i])
      mn=min(mn,dis(i,x));
    aa[i]={(int)des[i].size()-1,mn};
  }
  for(int i=1;i<=n;i++)
  {
    int ans=aa[i].lap*n+aa[i].ex;
    int lp=aa[i].lap,xx=aa[i].ex;
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      if(aa[j].lap>=lp)
      {
        int tlp=aa[j].lap,tex=aa[j].ex;
        tex+=dis(i,j);
        if(tex>=n)tlp++,tex-=n;
        if(tlp*n+tex>ans)
          ans=tlp*n+tex,lp=tlp,xx=tex;
      }
    }
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}