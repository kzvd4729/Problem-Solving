/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 15:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/416/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;int gr=-2e9,sm=2e9;
  for(int i=1;i<=n;i++)
  {
    string s;int x;char c;cin>>s>>x>>c;
    if(s==">=")
    {
      if(c=='Y')gr=max(gr,x);
      else sm=min(sm,x-1);
    }
    if(s=="<=")
    {
      if(c=='N')gr=max(gr,x+1);
      else sm=min(sm,x);
    }
    if(s==">")
    {
      if(c=='Y')gr=max(gr,x+1);
      else sm=min(sm,x);
    }
    if(s=="<")
    {
      if(c=='N')gr=max(gr,x);
      else sm=min(sm,x-1);
    }
  }
  if(gr>sm)cout<<"Impossible"<<endl;
  else cout<<gr<<endl;
  return 0;
}