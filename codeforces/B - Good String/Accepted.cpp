/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2019 21:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1140/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    if(s[0]=='>'||s[n-1]=='<')
      cout<<0<<"\n";
    else
    {
      int c1=0,c2=0;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='<')c1++;
        else break;
      }
      for(int i=n-1;i>=0;i--)
      {
        if(s[i]=='>')c2++;
        else break;
      }
      cout<<min(c1,c2)<<"\n";
    }
  }
  return 0;
}