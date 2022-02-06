/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 13:56                        
*  solution_verdict: Time limit exceeded on test 22          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 122700 KB                            
*  problem: https://codeforces.com/contest/540/problem/E
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
#define long long long
using namespace std;
const int N=1e6,R=1e9;
int aa[N+2],bb[N+2];map<int,long>bit;
void upd(int x,int vl)
{
  for( ;x>0;x-=x&-x)bit[x]+=vl;
}
long get(int x)
{
  long ret=0;
  for( ;x<=R;x+=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v;vector<int>a;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i]>>bb[i];
    a.push_back(aa[i]),a.push_back(bb[i]);
    v.push_back({aa[i],1});
    v.push_back({bb[i],1});
  }
  sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());
  for(int i=1;i<a.size();i++)
  {
    if(a[i]-a[i-1]-1>0)v.push_back({a[i]-1,a[i]-a[i-1]-1});
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i].first]=i;
  for(int i=1;i<=n;i++)swap(v[mp[aa[i]]],v[mp[bb[i]]]);
  //for(auto x:v)cout<<x.first<<" ";cout<<endl;
  long ans=0;
  for(auto x:v)
  {
    //cout<<x.first<<" "<<x.second<<endl;
    ans+=1LL*get(x.first)*x.second;
    upd(x.first,x.second);
  }
  cout<<ans<<endl;
  return 0;
}