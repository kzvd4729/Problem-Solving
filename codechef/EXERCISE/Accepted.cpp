/****************************************************************************************
*  @author: kzvd4729                                         created: 22-09-2019 22:45:48                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/COOK110A/problems/EXERCISE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    string s;cin>>s;int f=0,lo,hi;
    if(aa[1]!=-1)lo=aa[1],hi=aa[1];
    else lo=0,hi=inf;
    for(int i=2;i<=n;i++)
    {
      if(aa[i]==-1)
      {
        if(s[i-2]=='=');
        else if(s[i-2]=='>')
        {
          hi--;lo=0;if(hi==-1)f=1;
        }
        else
        {
          lo++;hi=inf;
        }
      }
      else
      {
        if(s[i-2]=='=')
        {
          if(lo>aa[i]||hi<aa[i])f=1;
        }
        else if(s[i-2]=='>')
        {
          if(hi<=aa[i])f=1;
        }
        else
        {
          if(lo>=aa[i])f=1;
        }
        lo=aa[i],hi=aa[i];
      }
      if(f)break;
    }
    if(f)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}