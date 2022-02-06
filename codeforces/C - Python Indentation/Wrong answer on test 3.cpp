/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/28/2017 09:40                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/909/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define mod 1000000007
using namespace std;
int main()
{
long n,f=-1,ans=1;
char c;
cin>>n;
while(n--)
{
cin>>c;
if(f==1)ans=(ans*2)%mod;
if(c=='f')f=0;
else 
{
if(f==0)f=1;
else if(f==1)f=-1;    
}
}
cout<<ans<<endl;
return 0;
}