/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 15:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1311/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2];
bool isOk(int n)
{
  for(int i=1;i<n;i++)
    if(aa[i]>aa[i+1])return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>aa[i];
     for(int i=1;i<=m;i++)cin>>bb[i];
    sort(bb+1,bb+m+1);
     int l=-1;
    for(int i=1;i<=m;i++)
    {
      if(l==-1)l=bb[i];
      else if(bb[i-1]+1!=bb[i])
      {
        //cout<<l<<" --> "<<bb[i-1]+1<<endl;
        sort(aa+l,aa+bb[i-1]+2);
        l=-1;i--;
      }
    }
    //cout<<l<<" --> "<<bb[m]+1<<endl;
    sort(aa+l,aa+bb[m]+2);
    if(isOk(n))cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}