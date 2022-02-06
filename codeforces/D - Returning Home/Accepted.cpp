/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2020 00:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 529 ms                                          memory_used: 42700 KB                             
*  problem: https://codeforces.com/contest/1422/problem/D
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
const long inf=1e18;
vector<pair<int,int> >ad[N+2];
void add(int a,int b,int c)
{
  //cout<<a<<" "<<b<<" "<<c<<endl;
  ad[a].push_back({b,c});
  ad[b].push_back({a,c});
}
long d[N+2];int qd[N+2];
void spfa(int n,int sr)
{
  for(int i=0;i<=n;i++)d[i]=inf,qd[i]=0;
  queue<int>q;q.push(sr);qd[sr]=1,d[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();qd[u]=0;
    for(auto x:ad[u])
    {
      if(d[u]+x.second<d[x.first])
      {
        d[x.first]=d[u]+x.second;
        if(!qd[x.first])q.push(x.first),qd[x.first]=1;
      }
    }
  }
  cout<<d[n]<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;int a,b,c,d;cin>>a>>b>>c>>d;
   vector<vector<int> >v(m);
  for(int i=0;i<m;i++)
  {
    int x,y;cin>>x>>y;v[i]={x,y,i+1};
    add(0,i+1,min(abs(a-x),abs(b-y)));
    add(m+1,i+1,abs(c-x)+abs(d-y));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<(int)v.size()-1;i++)
    add(v[i][2],v[i+1][2],min(abs(v[i][0]-v[i+1][0]),abs(v[i][1]-v[i+1][1])));
   sort(v.begin(),v.end(),[&](vector<int>a,vector<int>b){
    return a[1]<b[1];
  });
  for(int i=0;i<(int)v.size()-1;i++)
    add(v[i][2],v[i+1][2],min(abs(v[i][0]-v[i+1][0]),abs(v[i][1]-v[i+1][1])));
  add(0,m+1,abs(a-c)+abs(b-d));
   spfa(m+1,0);
    return 0;
}