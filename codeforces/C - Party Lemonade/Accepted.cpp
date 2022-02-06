/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/09/2018 10:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/913/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long l,n,x,r;
struct data
{
long am,ex,cs;
}tmp[32];
bool cmp(data A,data B)
{
return A.ex<B.ex;
}
long rec(long tt,long id)
{
if(tt==0)return 0;
if(id>n)return 9999999999999;
x=tt/tmp[id].am;
r=tt%tmp[id].am;
return tmp[id].cs*x+min(tmp[id].cs,rec(r,id+1));
}
int main()
{
cin>>n>>l;
for(long i=1;i<=n;i++)
{
cin>>tmp[i].cs;
tmp[i].am=pow(2,i-1);
tmp[i].ex=tmp[i].cs*pow(2,n-i);
}
sort(tmp+1,tmp+n+1,cmp);
/*for(long i=1;i<=n;i++)
{
cout<<tmp[i].ex<<" ";
}
cout<<endl;*/
cout<<rec(l,1)<<endl;
return 0;
}