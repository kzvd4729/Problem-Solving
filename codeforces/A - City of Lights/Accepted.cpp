/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/03/2020 17:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102465/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int f[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  int cnt=0,mx=0;
  while(k--)
  {
    int x;cin>>x;
    for(int i=x;i<=n;i+=x)
    {
      cnt-=f[i];f[i]^=1;
      cnt+=f[i];
    }
    mx=max(mx,cnt);
  }
  cout<<mx<<endl;
  return 0;
}