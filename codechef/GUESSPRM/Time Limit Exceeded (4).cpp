/****************************************************************************************
*  @author: kzvd4729                                         created: 14-07-2019 11:30:37                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 0.07 sec                                        memory_used: 15.4M                                
*  problem: https://www.codechef.com/JULY19A/problems/GUESSPRM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2];
vector<int>prime;
void seive(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    prime.push_back(i);
    for(int j=i+i;j<=N;j+=i)
      vis[j]=1;
  }
}
vector<long>fac(long a,int r)
{
  vector<long>v;
  for(auto x:prime)
  {
    if(a%x)continue;
    if(x>r)v.push_back(x);
    while(a%x==0)a/=x;
  }
  if(a!=1&&a>r)v.push_back(a);
  return v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int t;cin>>t;
  while(t--)
  {
    long x1=sqrt(1000000000),x2=5e4+100;
    cout<<1<<" "<<x1<<endl;
    int r;cin>>r;
    vector<long>v=fac(x1*x1-r,r);
    x2=x1*x1-r;
    cout<<1<<" "<<x2<<endl;
    cin>>r;
    long nm=x2*x2-r;
    for(auto x:v)
    {
      if(x<=r||nm%x)continue;
      cout<<1<<" "<<x<<endl;
      int rm;cin>>rm;if(rm)continue;
      cout<<2<<" "<<x<<endl;
      string s;cin>>s;
      break;
    }
  }
  return 0;
}