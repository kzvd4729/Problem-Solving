/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2020 11:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 10300 KB                             
*  problem: https://codeforces.com/contest/655/problem/E
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
#define long long long
using namespace std;
const int N=2e6,mod=1e9+7;
int dp[N+2],ls[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;string s;cin>>s;s="#"+s;
  dp[0]=1;memset(ls,-1,sizeof ls);
  for(int i=1;i<s.size();i++)
  {
    dp[i]=(dp[i-1]+dp[i-1])%mod;
    if(ls[s[i]-'a']!=-1)dp[i]=(dp[i]-dp[ls[s[i]-'a']-1]+mod)%mod;
    ls[s[i]-'a']=i;
  }
  set<pair<int,int> >st;
  for(int i=0;i<k;i++)st.insert({ls[i],i});
   for(int i=s.size();i<s.size()+n;i++)
  {
    dp[i]=(dp[i-1]+dp[i-1])%mod;
    pair<int,int>p=*st.begin();st.erase(p);
     if(p.first>0)dp[i]=(dp[i]-dp[p.first-1]+mod)%mod;
    st.insert({i,p.second});
  }
  cout<<dp[s.size()+n-1]<<endl;
  return 0;
}