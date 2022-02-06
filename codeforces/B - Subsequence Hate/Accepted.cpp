/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/02/2020 18:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1363/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#define long long long
using namespace std;
const int N=1e6;
void solve()
{
  string s;cin>>s;int n=s.size(),z=0;
  for(auto x:s)if(x=='0')z++;
   int ans=min(z,n-z),m=0;
  for(int i=1;i<=s.size();i++)
  {
    if(s[i-1]=='0')m++;//cout<<i-m<<" "<<n-i-(z-m)<<endl;
    ans=min(ans,i-m+z-m);
    ans=min(ans,m+n-z-(i-m));
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}