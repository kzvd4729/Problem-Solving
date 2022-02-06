/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/13/2020 22:01                        
*  solution_verdict: Wrong answer on pretest 9               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1301/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
   int mx=4*n*m-2*n-2*m;
  //cout<<mx<<endl;
   if(k>mx)cout<<"NO\n",exit(0);
   cout<<"YES\n";vector<pair<int,char> >ans;
  for(int i=1;i<=m;i++)
  {
    int rm=min(n-1,k);
    char c='D';if(i%2==0)c='U';
    if(rm)ans.push_back({rm,c});
     k-=rm;
     if(i<m&&k)
    {
      k--;
      ans.push_back({1,'R'});
    }
  }
  for(int i=m;i>=1;i--)
  {
    if(i>1)
    {
      if(k)
      {
        k--;
        ans.push_back({1,'L'});
      }
      if(k)
      {
        k--;
        ans.push_back({1,'R'});
      }
    }
    int rm=min(n-1,k);
    char c='U';if(i%2==0)c='D';
    if(rm)ans.push_back({rm,c});
     k-=rm;
     if(k)
    {
      k--;
      ans.push_back({1,'L'});
    }
  }
  cout<<ans.size()<<"\n";
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}