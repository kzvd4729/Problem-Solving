/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 9 ms                                            memory_used: 644 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int x,cnt;
int digit(int n)
{
int sum=0;
while(n)
{
sum+=n%10;
n/=10;
}
return sum;
}
int main()
{
cin>>x;
while(true)
{
if(x==0)cout<<cnt+1<<endl,exit(0);
x-=digit(x);
cnt++;
}
return 0;
}