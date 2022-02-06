/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/20/2018 14:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1025/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n;
pair<int,int>pp[N+2];
bool isprime(int x)
{
for(int i=2;i<=sqrt(x+1);i++)
{
if(x%i==0)return false;
}
return true;
}
void ck(int x)
{
if(x==1)return ;
if(!isprime(x))return ;
for(int i=1;i<=n;i++)
{
if(pp[i].first%x&&pp[i].second%x)return;
}
cout<<x<<endl,exit(0);
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 int a,b;cin>>n;n--;
cin>>a>>b;
if(n==0)cout<<a<<endl,exit(0);
for(int i=1;i<=n;i++){cin>>pp[i].first>>pp[i].second;}
for(int i=1;i<=sqrt(a+1);i++)if(a%i==0)ck(i),ck(a/i);
for(int i=1;i<=sqrt(b+1);i++)if(b%i==0)ck(i),ck(b/i);
cout<<-1<<endl;
return 0;
}