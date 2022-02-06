/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2021 20:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1473/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;
    int n1=a.size(),n2=b.size();
     if(n1<n2)swap(a,b),swap(n1,n2);
     int lcm=(n1*n2)/__gcd(n1,n2);
     string c,d;
    for(int i=1;i<=lcm/n1;i++)c+=a;
    for(int i=1;i<=lcm/n2;i++)d+=b;
     if(c==d)cout<<c<<endl;
    else cout<<-1<<endl;
  }
    return 0;
}