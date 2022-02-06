/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2020 20:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1305/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int vis[N+2];string s;
vector<int>ret()
{
  vector<int>v;for(int i=0;i<s.size();i++)vis[i]=0;
  int l=0,r=s.size()-1;
  while(l<r)
  {
    if(s[l]=='('&&s[r]==')')
    {
      v.push_back(l);vis[l]=1,vis[r]=1;
      v.push_back(r);
      l++,r--;
    }
    else if(s[l]=='(')r--;
    else l++;
  }
  sort(v.begin(),v.end());
  string a;
  for(int i=0;i<s.size();i++)if(!vis[i])a.push_back(s[i]);
  s=a;
  return v; 
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;vector<vector<int> >ans;
  while(true)
  {
    vector<int>v=ret();
    if(v.size()==0)break;
    ans.push_back(v);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
  {
    cout<<x.size()<<endl;
    for(auto z:x)cout<<z+1<<" ";
    cout<<endl;
  }
  return 0;
}