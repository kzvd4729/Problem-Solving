/****************************************************************************************
*  @author: kzvd4729                                         created: 10-03-2021 23:28:46                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/MARCH21A/problems/DENSEGRP
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
vector<int>nds;int lza[N+2],lzb[N+2];
vector<pair<int,int> >ad[N+2];
void dvd(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    nds.push_back(nd);return ;
  }
  int md=(lo+hi)/2;
  dvd(nd*2,lo,md,lt,rt);dvd(nd*2+1,md+1,hi,lt,rt);
}
int d[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,x,y;cin>>n>>m>>x>>y;
    vector<int>u,v;int tt=4*n+2;
    for(int i=1;i<=tt;i++)ad[i].clear(),lza[i]=0,lzb[i]=0;
    for(int i=1;i<=m;i++)
    {
      int a,b,c,d;cin>>a>>b>>c>>d;
      nds.clear();dvd(1,1,n,a,b);u=nds;
      nds.clear();dvd(1,1,n,c,d);v=nds;
      for(auto x:u)for(auto y:v)
      {
        lza[x]=1;lzb[y]=1;
        ad[x].push_back({y,1});
        //cout<<x<<" "<<y<<endl;
      }
    }
    nds.clear();dvd(1,1,n,x,x);x=nds[0];
    if((int)nds.size()>1)assert(0);
    //cout<<endl;
    for(int i=1;i<=n+n;i++)
    {
      if(lza[i])
      {
        ad[2*i].push_back({i,0});
        ad[2*i+1].push_back({i,0});
        lza[i*2]=1;lza[i*2+1]=1;
        //cout<<2*i<<" "<<i<<endl;
        //cout<<2*i+1<<" "<<i<<endl;
      }
      if(lzb[i])
      {
        ad[i].push_back({2*i,0});
        ad[i].push_back({2*i+1,0});
        lzb[i*2]=1;lzb[i*2+1]=1;
                //cout<<i<<" "<<2*i<<endl;
        //cout<<i<<" "<<2*i+2<<endl;
      }
      //cout<<2*i<<" "<<i<<endl;
      //cout<<2*i+1<<" "<<i<<endl;
    }
        for(int i=1;i<=tt;i++)d[i]=inf;
    deque<int>q;d[x]=0;q.push_back(x);
    while((int)q.size())
    {
      int nd=q.front();q.pop_front();
      for(auto x:ad[nd])
      {
        if(d[nd]+x.second<d[x.first])
        {
          d[x.first]=d[nd]+x.second;
          if(x.second)q.push_back(x.first);
          else q.push_front(x.first);
        }
      }
    }
    nds.clear();dvd(1,1,n,y,y);y=nds[0];
    if((int)nds.size()>1)assert(0);
    if(d[y]==inf)d[y]=-1;
    cout<<d[y]<<'\n';
    //cout<<x<<" "<<y<<endl;
  }
  return 0;
}