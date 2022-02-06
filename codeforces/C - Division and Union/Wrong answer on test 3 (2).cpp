/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 21:07                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1101/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
pair<int,int>pp[N+2];
bool cmp1(pair<int,int>p1,pair<int,int>p2)
{
  return p1.first<p2.first;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>pp[i].first>>pp[i].second;
    pp[n+1]={1e9,1e9};
    sort(pp+1,pp+n+1,cmp1);
    int mx=-1,ans=-1;
    for(int i=1;i<=n;i++)
    {
      if(mx<pp[i].first)
      {
        if(pp[i].second<pp[i+1].first)
          ans=i;
      }
      mx=max(mx,pp[i].second);
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