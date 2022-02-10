/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-22 14:12:42                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1341
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;

int isPrime[N+2];vector<int>prime;
void seive(int n)
{
  prime.push_back(2);isPrime[1]=1;
  for(int i=4;i<=n;i+=2)isPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(isPrime[i])continue;prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      isPrime[j]=1;
  }
}
vector<long>num,fr,dv;
void factorise(long x)
{
  int sq=sqrt(x+1);
  for(int j=0;prime[j]<=sq;j++)
  {
    int i=prime[j];if(x%i)continue;
    num.push_back(i);int cnt=0;
    while(x%i==0)x/=i,cnt++;fr.push_back(cnt);
    //if(x==1)break;
  }
  if(x!=1)num.push_back(x),fr.push_back(1);
}
void dfs(int id,long n)
{
  if(id==num.size())
  {
    dv.push_back(n);return ;
  }
  long ml=1;dfs(id+1,n);
  for(int i=0;i<fr[id];i++)
  {
    ml*=num[id];dfs(id+1,n*ml);
  }
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  seive(N);int t,tc=0;cin>>t;
  while(t--)
  {
    long a,b;cin>>a>>b;
    num.clear(),fr.clear(),dv.clear();
    factorise(a);dfs(0,1);
    sort(dv.begin(),dv.end());
    int ans=0;
    for(auto x:dv)
      if(x>=b&&a/x>=b)ans++;
    cout<<"Case "<<++tc<<": "<<ans/2<<"\n";
  }
  return 0;
}