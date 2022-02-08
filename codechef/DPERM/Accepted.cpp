/****************************************************************************************
*  @author: kzvd4729                                         created: 29-06-2019 20:18:29                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.63 sec                                        memory_used: 23.9M                                
*  problem: https://www.codechef.com/LTIME73A/problems/DPERM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bit[N+2];
void upd(int x)
{
  for( ;x>0;x-=x&-x)
    bit[x]++;
}
int get(int x,int n)
{
  int ret=0;
  for( ;x<=n;x+=x&-x)
    ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    int f=0;long ans=0;
    for(int i=1;i<=k;i++)
    {
      vector<int>v;
      for(int j=i;j<=n;j+=k)
        v.push_back(aa[j]);
      sort(v.begin(),v.end());
      int id=0;
      for(int j=i;j<=n;j+=k)
        if(v[id++]!=j)f=1;
      map<int,int>mp;
      for(int i=0;i<v.size();i++)
        mp[v[i]]=i+1;
      for(int i=1;i<=v.size();i++)bit[i]=0;
      for(int j=i;j<=n;j+=k)
      {
        int vl=mp[aa[j]];
        ans+=(get(vl,v.size()))*1LL;
        upd(vl);
      }
    }
    if(f)cout<<-1<<"\n";
    else cout<<ans<<"\n";
  }
  return 0;
}