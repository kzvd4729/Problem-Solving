/****************************************************************************************
*  @author: kzvd4729#                                        created: Feb/05/2020 15:28                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 200 KB                               
*  problem: https://codeforces.com/gym/101873/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
map<string,vector<string> >mp;
bool isRechable(string a,string b)
{
  if(a==b)return true;
  int ret=0;
  for(auto x:mp[a])
    ret|=isRechable(x,b);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string a,b,c;cin>>a>>c>>c>>c>>b;
    mp[a].push_back(b);
  }
  for(int i=1;i<=m;i++)
  {
    string a,b,c;cin>>a>>c>>c>>c>>b;
    if(isRechable(a,b))
      cout<<"Fact\n";
    else if(isRechable(b,a))
      cout<<"Alternative Fact\n";
    else cout<<"Pants on Fire\n";
  }
  return 0;
}