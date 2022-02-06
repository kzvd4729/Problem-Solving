/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/05/2021 23:21                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1481/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int fr[N+2],ls[N+2],fq[N+2],bit[N+2];
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
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,x;cin>>n;
  memset(fr,-1,sizeof fr);
  for(int i=1;i<=n;i++)
  {
    cin>>x;a[i]=x;
    if(fr[x]==-1)fr[x]=i;
    ls[x]=i;fq[x]++;
  }
  int ans=0;
  ans++;fq[x]--;ls[x]--;
  for(int i=n-1;i>=1;i--)
  {
    if(a[i]!=a[i+1])break;
    ans++,fq[x]--;ls[x]--;
  }
  vector<vector<int> >v;
  for(int i=1;i<=n;i++)
    if(fq[i])v.push_back({ls[i],fr[i],fq[i]});
   sort(v.begin(),v.end());int mx=0;
  for(auto x:v)
  {
    int g=get(x[1]-1);
    g+=x[2];upd(x[0],g);mx=max(mx,g);
  }
  cout<<n-ans-mx<<endl;
  return 0;
}