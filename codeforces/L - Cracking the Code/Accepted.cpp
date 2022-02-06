/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 19:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,arr[10];
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
//cout<<ans<<endl;
n=ans;
for(long i=2;i<=5;i++)
{
n=(n*ans)%100000;
}
for(long i=5;i>=1;i--)
{
arr[i]=n%10;
n/=10; 
}
for(long i=1;i<=5;i++)cout<<arr[i];
cout<<endl;
return 0;
}