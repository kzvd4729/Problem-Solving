/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/02/2021 22:41                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/1494/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=500,inf=1e9,mod=1e9+7;
 int k,a[N+2][N+2],sl[1000000+2];
vector<int>ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)cin>>a[i][j],mx=max(mx,a[i][j]);
  }
  int rt=n+1;k=n+1;sl[rt]=mx;
  vector<pair<int,int> >ed;
   for(int i=1;i<=n;i++)
  {
    vector<int>v;
    for(int j=1;j<=n;j++)
    {
      if(i==j)sl[i]=a[i][j];
      else v.push_back(a[i][j]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    if(v.back()!=mx)assert(0);
    int nd=rt,f=1;
    for(int j=(int)v.size()-2;j>=0;j--)
    {
      if(f)
      {
        int g=-1;
        for(auto x:ad[nd])
        {
          if(sl[x]==v[j]){g=x;break;}
        }
        if(g==-1)f=0;
        else nd=g;
      }
      if(f==0)
      {
        ++k;sl[k]=v[j];
        ad[nd].push_back(k);ed.push_back({nd,k});
        nd=k;
      }
    }
    ad[nd].push_back(i);ed.push_back({nd,i});
  }
    for(int i=n+1;i<=k;i++)
  {
    if((int)ad[i].size()<2)assert(0);
  }
  cout<<k<<'\n';
  for(int i=1;i<=k;i++)cout<<sl[i]<<" ";cout<<'\n';
  cout<<rt<<'\n';
  for(auto x:ed)cout<<x.first<<" "<<x.second<<'\n';
   return 0;
}