/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 20:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 17000 KB                             
*  problem: https://codeforces.com/contest/1077/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;long sum=0;
  vector<int>ans;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];bb[i]=aa[i];
    sum+=aa[i];
  }
  sort(bb+1,bb+n+1);
  long mx1=bb[n],mx2=bb[n-1];
   for(int i=1;i<=n;i++)
  {
    long rm=sum-aa[i];
    long mx;
    if(aa[i]==mx1)mx=mx2;
    else mx=mx1;
    if(mx+mx==rm)
    {
      ans.push_back(i);
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}