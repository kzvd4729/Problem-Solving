/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-27 23:32:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 182                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1319
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
long exgcd(long a,long b,long &x,long &y)
{
  if(!b){x=1,y=0;return a;}
  long x1,y1;
  long g=exgcd(b,a%b,x1,y1);
  x=y1,y=x1-(a/b)*y1;
  return g;
}
//remainder vector and modulo vector. modulo doesn't need to be co prime
long crt(vector<long>&a,vector<long>&m)
{
  long ans=a[0],lcm=m[0];
  for(int i=1;i<a.size();i++)
  {
    long x,y;long g=exgcd(lcm,m[i],x,y);
    if((a[i]-ans)%g!=0)assert(0);//no solution
    long md=(lcm/g)*m[i];
    ans=(ans+lcm*((x*((a[i]-ans)/g))%(m[i]/g)))%md;
    lcm=md;ans=(ans+lcm)%lcm;
  }
  return ans;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<long>a(n),m(n);
    for(int i=0;i<n;i++)
      cin>>m[i]>>a[i];
    cout<<"Case "<<++tc<<": "<<crt(a,m)<<"\n";
  }
  return 0;
}