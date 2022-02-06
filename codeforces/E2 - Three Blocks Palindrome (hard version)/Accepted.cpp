/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/14/2020 14:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 904 ms                                          memory_used: 163300 KB                            
*  problem: https://codeforces.com/contest/1335/problem/E2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],fr[200+2],a[200+2][N+2],tmp[N+2],fd[N+2];
vector<int>po[200+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(int i=1;i<=200;i++)po[i].clear(),fr[i]=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];fr[aa[i]]++;
      po[aa[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=200;i++)ans=max(ans,fr[i]);
     for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=200;j++)a[j][i]=a[j][i-1];
      a[aa[i]][i]++;
    }
    for(int i=1;i<=200;i++)//lft rgt
    {
      int id=0;
      for(auto x:po[i])tmp[++id]=x;
      for(int j=1;j<=200;j++)//middle
      {
        if(i==j)continue;int l=1,r=id;
        while(l<r)
        {
          ans=max(ans,l+l+a[j][tmp[r]]-a[j][tmp[l]]);
          l++,r--;
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}