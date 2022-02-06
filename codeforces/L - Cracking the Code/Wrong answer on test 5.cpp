/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 19:43                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans;
string s;
int main()
{
cin>>s;
for(long i=1;i<=s.size();i++)
{
if(i%2==1)ans=ans*10+s[i-1]-'0';
}
for(long i=s.size();i>=1;i--)
{
if(i%2==0)ans=ans*10+s[i-1]-'0';
}
n=1;
for(long i=1;i<=5;i++)
{
n=(n*ans)%100000;
}
cout<<n<<endl;
return 0;
}