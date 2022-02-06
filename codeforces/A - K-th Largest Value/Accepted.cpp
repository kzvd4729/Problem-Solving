/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2021 19:41                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1491/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    if(a[i]==1)cnt++;
  }
  while(q--)
  {
    int ty,id;cin>>ty>>id;
    if(ty==1)
    {
      if(a[id]==1)
      {
        cnt--;a[id]=0;
      }
      else
      {
        cnt++;a[id]=1;
      }
    }
    else
    {
      if(id<=cnt)cout<<1<<'\n';
      else cout<<0<<'\n';
    }
  }
    return 0;
}