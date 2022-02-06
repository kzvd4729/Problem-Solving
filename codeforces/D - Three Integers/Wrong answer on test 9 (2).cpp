/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 16:15                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1311/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int a,b,c;cin>>a>>b>>c;
    int ans=1e9;int aa,bb,cc;
    for(int i=1;i<=10000;i++)
    {
      for(int j=i;j<=10000;j+=i)
      {
        for(int k=j;k<=10000;k+=j)
        {
          int now=abs(i-a)+abs(j-b)+abs(k-c);
          if(now<ans)ans=now,aa=i,bb=j,cc=k;
        }
      }
    }
    cout<<ans<<"\n";
    cout<<aa<<" "<<bb<<" "<<cc<<"\n";
  }
  return 0;
}