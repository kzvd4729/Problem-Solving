/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/09/2020 16:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 701 ms                                          memory_used: 22100 KB                             
*  problem: https://codeforces.com/contest/1238/problem/G
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
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,c,c0;cin>>n>>m>>c>>c0;
    multiset<pair<int,int> >st;st.insert({0,c0});
    int cp=c0;
     vector<vector<int> >v(n+1);
    for(int i=0;i<n;i++)
    {
      v[i].resize(3);
      for(int j=0;j<3;j++)cin>>v[i][j];
    }
    v[n]={m,0,0};
    sort(v.begin(),v.end());
    long ans=0;int tim=0,f=0;
    for(int i=0;i<=n;i++)
    {
      int t=v[i][0],a=v[i][1],b=v[i][2];
       int gp=t-tim;cp-=gp;if(cp<0){f=1;break;}
      while((int)st.size()&&gp)
      {
        pair<int,int>p=*st.begin();st.erase(st.find(p));
        if(gp>=p.second)
        {
          ans+=1LL*p.first*p.second;
          gp-=p.second;
        }
        else
        {
          ans+=1LL*p.first*gp;
          st.insert({p.first,p.second-gp});
          gp=0;
        }
      }
      int am=min(c-cp,a);cp+=am;
      while(am<a&&(int)st.size())
      {
        pair<int,int>p=*st.rbegin();st.erase(st.find(p));
        if(p.first<=b)
        {
          st.insert(p);break;
        }
        if(am+p.second<=a)am+=p.second;
        else
        {
          st.insert({p.first,p.second-(a-am)});
          am=a;
        }
      }
      st.insert({b,am});tim=t;
    }
    if(f)cout<<-1<<" ";
    else cout<<ans<<" ";
  }
  return 0;
}