/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1307/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=26,inf=1e9;
long cnt[N+2],mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;long mx=0;
  for(auto x:s)
  {
    long c=x-'a';
    for(long i=0;i<26;i++)
    {
      mt[i][c]+=cnt[i];
      mx=max(mx,mt[i][c]);
    }
    cnt[c]++;mx=max(mx,cnt[c]);
  }
  cout<<mx<<endl;
  return 0;
}