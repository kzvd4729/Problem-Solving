/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 20:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1017/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,sum,oo[N+2],zz[N+2],oz[N+2],zo[N+2];
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  for(long i=n-1;i>=0;i--)
  {
    oo[i]=oo[i+1];
    zz[i]=zz[i+1];
    oz[i]=oz[i+1];
    zo[i]=zo[i+1];
     if(a[i]=='0'&&b[i]=='0')
    {
      sum+=oo[i]+oz[i];
      zz[i]++;
    }
    else if(a[i]=='0'&&b[i]=='1')
    {
      sum+=oz[i];
      zo[i]++;
    }
    else if(a[i]=='1'&&b[i]=='1')
    {
      sum+=zz[i];
      oo[i]++;
    }
    else
    {
      sum+=zz[i]+zo[i];
      oz[i]++;
    }
  }
  cout<<sum<<endl;
  return 0;
}