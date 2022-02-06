/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/15/2020 19:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 51100 KB                             
*  problem: https://codeforces.com/contest/1304/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2],r[N+2];int f[N+2];
map<string,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;string md;int sz=0;
  vector<string>ans;
  for(int i=1;i<=n;i++)
  {
    cin>>r[i];s[i]=r[i];
    reverse(r[i].begin(),r[i].end());
    if(r[i]==s[i])md=r[i];
    if(mp[s[i]])
    {
      sz+=2*((int)(s[i].size()));
      ans.push_back(s[i]);
    }
    mp[r[i]]=1;
  }
  sz+=md.size();
  cout<<sz<<endl;
  for(auto x:ans)cout<<x;
  cout<<md;
  reverse(ans.begin(),ans.end());
  for(auto x:ans)
  {
    string a=x;
    reverse(a.begin(),a.end());
    cout<<a;
  }
  cout<<endl;
  return 0;
}