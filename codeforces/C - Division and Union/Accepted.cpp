/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 234 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1101/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int ans[N+2];
pair<int,pair<int,int> >pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>pp[i].first>>pp[i].second.first;
      pp[i].second.second=i;
    }
    for(int i=1;i<=n;i++)ans[i]=1;
    sort(pp+1,pp+n+1);
    int mx=pp[1].second.first,f=0;
    for(int i=2;i<=n;i++)
    {
      if(mx<pp[i].first)
      {
        for(int j=1;j<i;j++)
          ans[pp[j].second.second]=2;
        f=1;break;
      }
      mx=max(mx,pp[i].second.first);
    }
    if(f==0)cout<<-1<<endl;
    else
    {
      for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
      cout<<"\n";
    }
  }
  return 0;
}