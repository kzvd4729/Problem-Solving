/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2019 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/1234/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int aa[N+2];long ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;long ans=0;
  for(int i=1;i<=m;i++)
  {
    cin>>aa[i];if(i==1)continue;
    vector<int>v;
    v.push_back(aa[i]-1);
    v.push_back(aa[i]);v.push_back(n);
     v.push_back(aa[i-1]-1);v.push_back(aa[i-1]);
     int now=0;
    sort(v.begin(),v.end());
    for(auto x:v)
    {
      int a,b;
      if(x<aa[i])a=aa[i];else if(aa[i]==x)a=1;
      else a=aa[i]+1;
       if(x<aa[i-1])b=aa[i-1];else if(aa[i-1]==x)b=1;
      else b=aa[i-1]+1;
       ad[now+1]+=abs(a-b);ad[x+1]-=abs(a-b);
      now=x;
    }
  }
  for(int i=1;i<=n;i++)
    ad[i]+=ad[i-1],cout<<ad[i]<<" ";
  return 0;
}