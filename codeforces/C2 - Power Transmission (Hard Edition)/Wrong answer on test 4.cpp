/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/30/2020 13:37                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 6100 KB                              
*  problem: https://codeforces.com/contest/1163/problem/C2
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
int a[N+2],b[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   map<pair<int,int>,vector<pair<int,int> > >mp;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      int up=b[j]-b[i],dw=a[j]-a[i];
      int gc=__gcd(abs(up),abs(dw));
      up/=gc,dw/=gc;
       if(dw<0)dw*=-1,up*=-1;
      if(up==0||dw==0)up=abs(up),dw=abs(dw);
      mp[{up,dw}].push_back({i,j});
    }
  }
  int id=0;
  for(auto v:mp)
  {
    set<pair<int,int> >st;
    for(auto x:v.second)
    {
      int i=x.first,j=x.second;
       long up=b[j]-b[i],dw=a[j]-a[i];
      int gc=__gcd(abs(up),abs(dw));
      up/=gc,dw/=gc;
       if(dw<0)dw*=-1,up*=-1;
      if(up==0||dw==0)up=abs(up),dw=abs(dw);
       up*=(-a[i]);up+=dw*b[i];
       gc=__gcd(abs(up),abs(dw));//cout<<"*"<<gc<<endl;
      if(gc)up/=gc,dw/=gc;
       if(dw<0)dw*=-1,up*=-1;
      if(up==0||dw==0)up=abs(up),dw=abs(dw);
       st.insert({up,dw});
    }
    ans[++id]=st.size();
  }
  long tt=0;
  for(int i=id-1;i>=1;i--)ans[i]+=ans[i+1];
  for(int i=1;i<=id;i++)tt+=1LL*(ans[i]-ans[i+1])*ans[i+1];
  cout<<tt<<endl;
  return 0;
}