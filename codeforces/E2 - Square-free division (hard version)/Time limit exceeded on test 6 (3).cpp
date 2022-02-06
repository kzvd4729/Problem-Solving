/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2021 23:46                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 71800 KB                             
*  problem: https://codeforces.com/contest/1497/problem/E2
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
const int R=1e7;
 int fc[R+2];bool cnt[R+2];
void cal()
{
  for(int i=2;i<=R;i++)
  {
    if(fc[i])continue;
    for(int j=i;j<=R;j+=i)fc[j]=i;
  }
}
int convert(int x)
{
  vector<int>v;
  while(x>1)
  {
    v.push_back(fc[x]);cnt[fc[x]]^=1;
    x/=fc[x];
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
    int ret=1;
  for(auto x:v)
  {
    if(cnt[x])ret*=x,cnt[x]=0;
  }
  return ret;
}
 int a[N+2];
void compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(a[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)a[i]=mp[a[i]];
}
 int ls[N+2];
vector<pair<int,int> >segmentation(int n)
{
  int lt=1;vector<pair<int,int> >ret;
  for(int i=1;i<=n;i++)
  {
    if(ls[a[i]])
    {
      ret.push_back({lt,i-1});
      for(int j=lt;j<i;j++)ls[a[j]]=0;
      lt=i;
    }
    ls[a[i]]=1;
  }
  ret.push_back({lt,n});
  for(int i=lt;i<=n;i++)ls[a[i]]=0;
  return ret;
}
int fr[N+2];
vector<int>findMin(vector<pair<int,int> >v)
{
  int sz=v.size();vector<int>ret(200000+2);
  for(int i=0;i<sz-1;i++)
  {
    vector<int>now;
    for(int j=v[i].first;j<=v[i].second;j++)fr[a[j]]=1;
    for(int j=v[i+1].first;j<=v[i+1].second;j++)
    {
      if(fr[a[j]]==0)continue;
      if(fr[a[j]]==1)now.push_back(j);
      fr[a[j]]++;
    }
    if((int)now.size()<(int)ret.size())ret=now;
     for(int j=v[i].first;j<=v[i].second;j++)fr[a[j]]=0;
  }
  return ret;
}
int solve(int n,int k)
{
  while(true)
  {
    vector<pair<int,int> >v=segmentation(n);
    if((int)v.size()==1)break;
     vector<int>x=findMin(v);
    if((int)x.size()>k)break;
     k-=(int)x.size();
     vector<int>tmp;
    for(int i=1;i<=n;i++)tmp.push_back(a[i]);
     reverse(x.begin(),x.end());
    for(auto id:x)tmp.erase(tmp.begin()+id-1);
     n=tmp.size();
    for(int i=1;i<=n;i++)a[i]=tmp[i-1];
     //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  }
  vector<pair<int,int> >v=segmentation(n);
  return (int)v.size();
}
 int b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal();
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]=convert(a[i]);
     compress(n);
    for(int i=1;i<=n;i++)b[i]=a[i];
     int ans=solve(n,k);
    for(int i=1;i<=n;i++)a[i]=b[n-i+1];
    ans=min(ans,solve(n,k));
     cout<<ans<<" ";
      }
  return 0;
}