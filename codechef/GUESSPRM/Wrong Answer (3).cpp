/****************************************************************************************
*  @author: kzvd4729                                         created: 06-07-2019 11:43:49                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.16 sec                                        memory_used: 15.4M                                
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
    long x1=100000,x2=99999;
    cout<<1<<" "<<x1<<endl;
    int r;cin>>r;
    vector<long>v1=fac(x1*x1-r,r);
    cout<<1<<" "<<x2<<endl;
    cin>>r;
    vector<long>v2=fac(x2*x2-r,r);
    sort(v1.begin(),v1.end());
    for(auto x:v2)
    {
      if(binary_search(v1.begin(),v1.end(),x))
      {
        cout<<2<<" "<<x<<endl;
        string x;cin>>x;
        break;
      }
    }
  }
  return 0;
}