/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2019 21:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1194/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[30],an[30];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tc;cin>>tc;
  while(tc--)
  {
    string s,t,p;cin>>s>>t>>p;
    int a=0;memset(fr,0,sizeof(fr));
    memset(an,0,sizeof(an));
    for(auto x:t)
    {
      if(a==s.size())break;
      if(x==s[a])a++;
    }
    if(a!=s.size())
    {
      cout<<"NO"<<"\n";continue;
    }
    for(auto x:t)
      an[x-'a']++;
    for(auto x:s)
      fr[x-'a']++;
    for(auto x:p)
      fr[x-'a']++;
    int f=0;
    for(int i=0;i<26;i++)
    {
      if(fr[i]<an[i])
      {
        cout<<"NO\n";f=1;break;
      }
    }
    if(!f)cout<<"YES\n";
  }
  return 0;
}