/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2020 15:51                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 158100 KB                            
*  problem: https://codeforces.com/contest/685/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>pp[N+2];
void compress(int n,int k)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(pp[i].second);
  sort(v.begin(),v.end());map<int,int>mp;
  v.erase(unique(v.begin(),v.end()),v.end());
   int cnt=k;mp[v[0]]=cnt;
  for(int i=1;i<n;i++)
  {
    if(v[i]>=v[i-1]+k)cnt+=k;
    else cnt+=v[i]-v[i-1];
    mp[v[i]]=cnt; 
  }
  for(int i=1;i<=n;i++)pp[i].second=mp[pp[i].second];
}
int n,fr[400*N+2];long ans[N+2];
const int inf=2e9;
void add(int c,int k,int f,int tm)
{
  for(int i=c;i<=c+k-1;i++)
  {
    ans[fr[i]]-=(inf-tm);fr[i]+=f;
    ans[fr[i]]+=(inf-tm);
  }
  ans[0]=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1);compress(n,k);
    //for(int i=1;i<=n;i++)cout<<pp[i].first<<" "<<pp[i].second<<endl;
    for(int i=1;i<=n;i++)
    add(pp[i].second,k,1,pp[i].first);
  for(int i=1;i<=n;i++)
    add(pp[i].second,k,-1,pp[i].first+k);
   for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}