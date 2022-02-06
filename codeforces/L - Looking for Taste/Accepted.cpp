/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 00:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 935 ms                                          memory_used: 100 KB                               
*  problem: https://codeforces.com/gym/101991/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  freopen("looking.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;ans|=x;
    }
    cout<<ans<<endl;
  }
  return 0;
}