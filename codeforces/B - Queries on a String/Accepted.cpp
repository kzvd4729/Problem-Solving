/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2019 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/598/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int m;cin>>m;int n=s.size();
  while(m--)
  {
    int l,r,k;cin>>l>>r>>k;
    int df=(r-l+1);k%=df;
    if(k==0)k=df;int id=r-k+1;
    //cout<<id<<endl;
    string ss;
    for(int i=1;i<=n;i++)
    {
      if(i>=l&&i<=r)
      {
        for(int j=id;j<=r;j++)
          ss.push_back(s[j-1]);
        for(int j=l;j<id;j++)
          ss.push_back(s[j-1]);
        i=r;
      }
      else ss.push_back(s[i-1]);
    }
    s=ss;//cout<<s<<endl;
  }
  cout<<s<<endl;
  return 0;
}