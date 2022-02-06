/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 23:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 16000 KB                             
*  problem: https://codeforces.com/contest/1178/problem/B
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int pre[N+2],suf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();s="#"+s+"#";
   for(int i=1;i<=n;i++)
    pre[i]=pre[i-1]+(s[i]=='v'&&s[i-1]=='v');
   for(int i=n;i>=1;i--)
    suf[i]=suf[i+1]+(s[i]=='v'&&s[i+1]=='v');
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i]!='o')continue;
    ans+=1LL*pre[i]*suf[i];
  }
  cout<<ans<<endl;
  return 0;
}