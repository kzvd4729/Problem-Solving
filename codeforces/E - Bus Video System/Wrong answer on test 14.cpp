/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 19:47                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/978/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,x,mx=-2e9,mn=2e9,sum,w;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>w;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    sum+=x;
    mx=max(mx,sum);
    mn=min(mn,sum);
  }
  if(mx>w||abs(mn)>w)cout<<0<<endl;
  else
  {
    int r=min(w,w-mx);
    int l=max(0,-mn);
    //if(l>r)cout<<0<<endl;
    cout<<r-l+1<<endl;
  }
  return 0;
}