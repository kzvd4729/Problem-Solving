/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2020 18:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/978/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans[N+2],ex[N+2],cnt[N+2];
vector<vector<int> >v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int s,d,c;cin>>s>>d>>c;
    v[s].push_back({d,i});
    ex[d]=i;cnt[i]=c;
  }
  set<vector<int> >st;int f=0;
  for(int i=1;i<=n;i++)
  {
    for(auto x:v[i])st.insert(x);
    if(ex[i])
    {
      if(cnt[ex[i]])f=1;
      ans[i]=m+1;continue;
    }
    if(st.size())
    {
      vector<int>tmp=*st.begin();
      int rm=--cnt[tmp[1]];ans[i]=tmp[1];
      if(rm==0)st.erase(tmp);
    }
  }
  if(f)cout<<-1<<endl;
  else for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}