/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 00:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/gym/101991/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<string,vector<int>>mp;
int make(int x)
{
  if(x%5==4)return x+1;
  if(x%5==1)return x-1;
  return x;
}
int main()
{
  freopen("coffee.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;mp.clear();
    for(int i=1;i<=n;i++)
    {
      string c;cin>>c;
      vector<int>v(3);
      for(int i=0;i<3;i++)cin>>v[i];
      mp[c]=v;
    }
    int dl=100/q;
    while(q--)
    {
      string a,b,c;cin>>a>>b>>c;
      if(b=="small")
        cout<<a<<" "<<make(mp[c][0]+dl)<<"\n";
      else if(b=="medium")
        cout<<a<<" "<<make(mp[c][1]+dl)<<"\n";
      else cout<<a<<" "<<make(mp[c][2]+dl)<<"\n";
    }
  }
  return 0;
}