/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-23 21:34:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 140                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10927
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<pair<int,int>,vector<pair<pair<int,int>,int> > >mp;
int mx[N+2];
bool cmp(pair<pair<int,int>,int>p1,pair<pair<int,int>,int>p2)
{
  pair<int,int>p3=p1.first,p4=p2.first;
  if(abs(p3.first)!=abs(p4.first))
    return abs(p3.first)<abs(p4.first);
  return abs(p3.second)<abs(p4.second);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,tc=0;
  while(cin>>n)
  {
    if(!n)break;mp.clear();
    for(int i=1;i<=n;i++)
    {
      int x,y,z;cin>>x>>y>>z;
      int gc=__gcd(abs(x),abs(y));
      if(!gc)assert(0);x/=gc,y/=gc;
      mp[{x,y}].push_back({{x*gc,y*gc},z});
    }
    vector<pair<int,int> >ans;
    for(auto x:mp)
    {
      sort(x.second.begin(),x.second.end(),cmp);
      if(x.second.size()==1)continue;
      mx[0]=x.second[0].second;
      for(int i=1;i<x.second.size();i++)
        mx[i]=max(mx[i-1],x.second[i].second);
      for(int i=1;i<x.second.size();i++)
        if(mx[i-1]>=x.second[i].second)
          ans.push_back(x.second[i].first);
    }
    sort(ans.begin(),ans.end());
    cout<<"Data set "<<++tc<<":"<<"\n";
    if(ans.size()==0)
      cout<<"All the lights are visible."<<"\n";
    else
    {
      cout<<"Some lights are not visible:"<<"\n";
      for(int i=0;i<ans.size();i++)
      {
        cout<<"x = "<<ans[i].first<<", y = "<<ans[i].second;
        if(i==ans.size()-1)cout<<"."<<"\n";
        else cout<<";"<<"\n";
      }
    }
  }
  return 0;
}