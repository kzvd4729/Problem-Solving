/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2018 11:43                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 561 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/994/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,k;
long ans[N+2];
struct data
{
int a,b,id;
}arr[N+2];
bool cmp(data A,data B)
{
return A.a<B.a;
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)
cin>>arr[i].a;
for(int i=1;i<=n;i++)
cin>>arr[i].b;
for(int i=1;i<=n;i++)
arr[i].id=i;
sort(arr+1,arr+n+1,cmp);
priority_queue<int>pq;;
long sum=0;
for(int i=1;i<=n;i++)
{
sum+=(arr[i].b*1LL);
ans[arr[i].id]=sum;
pq.push(-arr[i].b);
if(pq.size()>k)
{
int tp=-pq.top();
pq.pop();
sum-=(tp*1LL);
}
}
for(int i=1;i<=n;i++)
cout<<ans[i]<<" ";
cout<<endl;
return 0;
}