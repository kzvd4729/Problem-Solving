/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 18:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/B
****************************************************************************************/
#include<bits/stdc++.h> 
#define long long long 
using namespace std; 
double n=1.000000011,ans,x,arr[100]; 
long z,cnt; 
void bigmod(void) 
{
arr[0]=n;
for(long i=1; ;i++) 
{
if(pow(2,i)>=z)break; 
arr[i]=arr[i-1]*arr[i-1]; 
ans=arr[i]; 
cnt=pow(2,i); 
} 
for(long i=50;i>=1;i--)
{
if((cnt+pow(2,i))>z)continue; 
cnt+=pow(2,i); 
ans*=arr[i]; 
}
} 
int main() 
{
cin>>x>>z; 
bigmod(); 
ans*=x;
if(z<5)
{
for(long i=1;i<=z;i++)x*=n;
cout<<setprecision(10)<<fixed<<x<<endl;
return 0;    
} 
cout<<setprecision(10)<<fixed<<ans<<endl; 
return 0; 
}