/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2019 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 22600 KB                             
*  problem: https://codeforces.com/contest/1187/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int mx[28][N+2],fr[30];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int id=0;
  for(auto x:s)
  {
    int c=x-'a';
    fr[c]++;mx[c][fr[c]]=id;
    id++;
  }
  int m;cin>>m;
  while(m--)
  {
    string s;cin>>s;memset(fr,0,sizeof(fr));
    int ans=-1;
    for(auto x:s)
    {
      int c=x-'a';
      fr[c]++;
      ans=max(ans,mx[c][fr[c]]);
    }
    cout<<ans+1<<"\n";
  }
  return 0;
}