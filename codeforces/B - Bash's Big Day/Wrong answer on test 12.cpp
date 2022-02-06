/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 23:49                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/757/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int cnt[N+2],mx;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n;
  while(n--)
  {
    cin>>x;
    for(int i=2;i<=sqrt(x+1);i++)
    {
      if(x%i==0)
      {
        cnt[i]++;
        mx=max(mx,cnt[i]);
        while(x%i==0)x/=i;
      }
    }
    if(x!=1)
    {
      cnt[x]++;
      mx=max(mx,cnt[x]);
    }
  }
  cout<<mx<<endl;
  return 0;
}