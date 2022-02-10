/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 545 ms                                          memory_used: 84.6 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,a;
struct point
{
  int x,y;
}arr[100005];
set<pair<int,pair<int,int> > >st;
map<int,vector<int> >mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>a;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].x>>arr[i].y;
    mp[arr[i].x].push_back(arr[i].y);
  }
  int ans=0,id=0;
  for(int i=1;i<=1000000;i++)
  {
    int xx=i;
    int yy=a/i;
    for(auto z:mp[xx])
      st.insert({-z,{xx,++id}});
    while(true)
    {
      if(st.size()==0)break;
      pair<int,pair<int,int> >p=*st.begin();
      if(-p.first>yy)st.erase(p);
      else break;
    }
    ans=max(ans,(int)st.size());
  }
  cout<<ans<<endl;
  return 0;
}