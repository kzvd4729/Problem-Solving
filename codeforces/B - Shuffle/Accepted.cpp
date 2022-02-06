/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1366/problem/B
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e2;
int lt[N+2],rt[N+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(vs,0,sizeof vs);
    int n,x,m;cin>>n>>x>>m;lt[0]=x,rt[0]=x,vs[0]=1;
    for(int i=1;i<=m;i++)
    {
      cin>>lt[i]>>rt[i];
      for(int j=0;j<i;j++)
      {
        if(lt[j]>rt[i]||rt[j]<lt[i])continue;
        if(vs[j])vs[i]=1;
      }
    }
    vector<pair<int,int> >v;
    for(int i=0;i<=m;i++)if(vs[i])v.push_back({lt[i],rt[i]});
    sort(v.begin(),v.end());int ans=0,l=0;
    for(auto x:v)
    {
      //cout<<x.first<<" "<<x.second<<endl;
      if(x.first>l)l=x.first-1;
      if(x.second>l){ans+=x.second-l;l=x.second;}
    }
    cout<<ans<<endl;
  }
    return 0;
}