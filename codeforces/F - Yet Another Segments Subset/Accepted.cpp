/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/16/2020 13:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1399/problem/F
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
const int N=1e4,inf=1e9;
vector<pair<int,int> >a;
void compress()
{
  vector<int>v;
  for(int i=0;i<a.size();i++)v.push_back(a[i].first),v.push_back(a[i].second);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=0;i<a.size();i++)a[i].first=mp[a[i].first],a[i].second=mp[a[i].second];
}
int dp[N+2],bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)bit[x]=max(bit[x],vl);
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret=max(ret,bit[x]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    a.push_back({1,inf});compress();
     sort(a.begin(),a.end(),[&](pair<int,int>p,pair<int,int>q){
      return p.second-p.first<q.second-q.first;
    });
    vector<vector<int> >b;
    for(int i=0;i<a.size();i++)b.push_back({a[i].first,a[i].second,i});
    sort(b.begin(),b.end(),[&](vector<int>p,vector<int>q){
        return p[1]<q[1];
    });
    for(int i=0;i<a.size();i++)
    {
      vector<vector<int> >tmp;
      for(int j=0;j<b.size();j++)
      {
        if(b[j][0]>=a[i].first&&b[j][1]<=a[i].second&&b[j][2]<i)
          tmp.push_back(b[j]);
      }
      for(int j=0;j<=n+n+2;j++)bit[j]=0;
      dp[i]=0;
      for(int j=0;j<tmp.size();j++)
      {
        int ght=dp[tmp[j][2]]+get(tmp[j][0]-1);
        dp[i]=max(dp[i],ght);upd(tmp[j][1],ght);
      }
      dp[i]++;
    }
    cout<<dp[a.size()-1]-1<<" ";
  }
  cout<<"\n";
  return 0;
}