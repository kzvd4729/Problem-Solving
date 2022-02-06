/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 20:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1153/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,t;cin>>n>>t;int mn=1e9,b;
  for(int i=1;i<=n;i++)
  {
    int s,d;cin>>s>>d;
    while(true)
    {
      if(s>=t)
      {
        int wt=s-t;
        if(wt<mn)
        {
          mn=wt;b=i;
        }
        break;
      }
      s+=d;
    }
  }
  cout<<b<<endl;
  return 0;
}