/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2018 10:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/964/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,a,b,c,t,tt[10004];
    void case1(void)
{
long sum=0;
for(int i=1;i<=n;i++)
{
sum+=((t-tt[i])*c)*1LL;
sum+=(a-((t-tt[i])*b))*1LL;
}
cout<<sum<<endl;
exit(0);
}
void case2(void)
{
cout<<n*a<<endl;
exit(0);
}
       int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n>>a>>b>>c>>t;
for(int i=1;i<=n;i++)cin>>tt[i];
 if(c>b)case1();
else case2();
    return 0;
}