/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 21:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 13500 KB                             
*  problem: https://codeforces.com/contest/1130/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n+n;i++)
  {
    int x;cin>>x;
    v[x].push_back(i);
  }
  int pa=1,pb=1;long ans=0;
  for(int i=1;i<=n;i++)
  {
    int a=v[i][0],b=v[i][1];
    int mn=abs(pa-a)+abs(pb-b);
    mn=min(mn,abs(pa-b)+abs(pb-a));
    ans+=mn*1LL;pa=a,pb=b;
  }
  cout<<ans<<endl;
  return 0;
}