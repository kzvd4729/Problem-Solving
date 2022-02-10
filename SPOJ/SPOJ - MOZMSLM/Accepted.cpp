/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-29 21:16:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 17.4                            
*  problem: https://vjudge.net/problem/SPOJ-MOZMSLM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t;
long ss[N+4],mm[N+4];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;
    memset(ss,0,sizeof(ss));
    memset(mm,0,sizeof(mm));
    for(int i=s.size()-1;i>=0;i--)
    {
      if(s[i]=='s')ss[i]=ss[i+1]+1;
      else ss[i]=ss[i+1];
    }
    for(int i=s.size()-1;i>=0;i--)
    {
      if(s[i]=='m')mm[i]=mm[i+1]+ss[i+1];
      else mm[i]=mm[i+1];
    }
    long ans=0;
    for(int i=0;i<s.size();i++)
      if(s[i]=='s')ans+=mm[i+1];
    cout<<ans<<endl;
  }
  return 0;
}