/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2020 16:23                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/633/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e4;
int n,aa[N+2],fib[N+2],con[N+2],m;
void compress()
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(aa[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<int,int>mp;
  for(int i=0;i<v.size();i++)
  {
    mp[v[i]]=i+1;con[i+1]=v[i]%m;
  }
  for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
}
bool vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
   compress();
    fib[1]=1;fib[2]=1;
  for(int i=3;i<=30000;i++)fib[i]=(fib[i-1]+fib[i-2])%m;
   int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>l>>r;
    for(int i=1;i<=r;i++)vs[aa[i]]=1;
     long ans=0;int cnt=1;
    for(int i=1;i<=30000;i++)
    {
      if(vs[i])
      {
        ans+=con[i]*fib[cnt++];
        vs[i]=0;
      }
    }
    cout<<ans%m<<"\n";
  }
  return 0;
}