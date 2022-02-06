/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2018 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1081/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans[N+2];
pair<int,int>aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i].first;aa[i].first=n-aa[i].first;
    aa[i].second=i;
  }
  sort(aa+1,aa+n+1);
  int cl=1;int f=0;
  for(int i=1;i<=n; )
  {
    int x=aa[i].first;
    for(int j=i;j<i+aa[i].first;j++)
    {
      if(aa[j].first!=x)f=1;
      ans[aa[j].second]=cl;
      //ans[j]=cl;
    }
    i+=aa[i].first;cl++;
  }
  if(f)cout<<"Impossible"<<endl;
  else
  {
    cout<<"Possible"<<endl;
    for(int i=1;i<=n;i++)
      cout<<ans[i]<<" ";
    cout<<endl;
  }
  return 0;
}