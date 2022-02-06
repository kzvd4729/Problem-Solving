/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 21:12                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 2300 KB                              
*  problem: https://codeforces.com/contest/1101/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
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
    pp[n+1]={1e9,{1e9,1}};
    sort(pp+1,pp+n+1);
    int mx=-1,ans=-1;
    for(int i=1;i<=n;i++)
    {
      if(mx<pp[i].first)
      {
        if(pp[i].second.first<pp[i+1].first)
          ans=pp[i].second.second;
      }
      mx=max(mx,pp[i].second.first);
    }
    if(ans==-1)cout<<-1<<endl;
    else
    {
      for(int i=1;i<=n;i++)
      {
        if(i==ans)cout<<1<<" ";
        else cout<<2<<" ";
      }
      cout<<"\n";
    }
  }
  return 0;
}