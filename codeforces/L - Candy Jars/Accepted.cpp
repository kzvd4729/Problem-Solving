/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2019 00:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100814/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4,inf=1e9;
int f[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;memset(f,0,sizeof(f));
    for(int i=n-1;i<=2000;i+=n*(n-1))
    {
      for(int j=i;j>max((i-(n-1)),0);j--)
        f[j]=1;
    }
    bool ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;ans|=!f[x];
    }
    if(ans)cout<<"Alice\n";else cout<<"Bob\n";
  }
  return 0;
}